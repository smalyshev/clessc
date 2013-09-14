/*
 * Copyright 2012 Bram van der Kroef
 *
 * This file is part of LESS CSS Compiler.
 *
 * LESS CSS Compiler is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * LESS CSS Compiler is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with LESS CSS Compiler.  If not, see <http://www.gnu.org/licenses/>. 
 *
 * Author: Bram van der Kroef <bram@vanderkroef.net>
 */

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <stdexcept>
#include <unistd.h>

#include "LessTokenizer.h"
#include "LessParser.h"
#include "value/ValueProcessor.h"
#include "ParameterRulesetLibrary.h"
#include "CssWriter.h"
#include "CssPrettyWriter.h"
#include "Stylesheet.h"
#include "IOException.h"

extern "C" {
#include "php.h"
#include "php_less.h"
}

using namespace std;

Stylesheet* processInput(istream* in){
  ValueProcessor vp;
  ParameterRulesetLibrary pr(&vp);
  LessTokenizer tokenizer(in);
  LessParser parser(&tokenizer, &pr, &vp);
  Stylesheet* s = new Stylesheet();
  
  try{
    parser.parseStylesheet(s);
  } catch(const exception* e) {
	ostringstream errs;
    errs << "Line " << tokenizer.getLineNumber() << ", Column " << 
      tokenizer.getColumn() << " Parse Error: " << e->what() << endl;
	throw runtime_error(errs.str());
  }
  
  return s;
}
void writeOutput (ostream* out, Stylesheet* stylesheet, bool format) {
  CssWriter *w;
  w = format ? new CssPrettyWriter(out) : new CssWriter(out);
  
  w->writeStylesheet(stylesheet);
  *out << endl;
  delete w;
}

int process_lessc(const char *input, int input_len, char **output, int *output_len)
{
	Stylesheet* s;
	istringstream instream(input);

	try {
		s = processInput(&instream);
	    if (s != NULL) {
			ostringstream out;
			writeOutput(&out, s, false);
			delete s;
			string outs(out.str());
			*output = estrndup(outs.c_str(), outs.length());
			*output_len = outs.length();
			return SUCCESS;
		}
	} catch(const exception &e) {
		// should save in global for later reporting
	}
	return FAILURE;
}

