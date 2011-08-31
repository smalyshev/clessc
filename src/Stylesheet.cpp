#include "Stylesheet.h"

Declaration::Declaration(string* property) {
  this->property = property;
  value = NULL;
}

Declaration::~Declaration() {
  if (property != NULL)
    delete property;

  if (value != NULL) {
    while (!value->empty()) {
      delete value->back();
      value->pop_back();
    }
    delete value;
  }
}

void Declaration::setProperty(string* property) {
  this->property = property;
}
void Declaration::setValue(vector<string*>* value) {
  this->value = value;
}
string* Declaration::getProperty() {
  return property;
}
vector<string*>* Declaration::getValue() {
  return value;
}

Ruleset::~Ruleset() {
  if (selector != NULL) {
    while (!selector->empty()) {
      delete selector->back();
      selector->pop_back();
    }
    delete selector;
  }
  
  while (!declarations.empty()) {
    delete declarations.back();
    declarations.pop_back();
  }
}

void Ruleset::setSelector (vector<string*>* selector) {
  this->selector = selector;
}
void Ruleset::addDeclaration (Declaration* declaration) {
  declarations.push_back(declaration);
}
vector<string*>* Ruleset::getSelector() {
  return selector;
}
vector<Declaration*>* Ruleset::getDeclarations() {
  return &declarations;
}

AtRule::AtRule (string* keyword) {
  this->keyword = keyword;
  rule = NULL;
}

AtRule::~AtRule() {
  if (keyword != NULL)
    delete keyword;

  if (rule != NULL) {
    while (!rule->empty()) {
      delete rule->back();
      rule->pop_back();
    }
    delete rule;
  }
}

void AtRule::setKeyword (string* keyword) {
  this->keyword = keyword;
}
void AtRule::setRule(vector<string*>* rule) {
  this->rule = rule;
}
string* AtRule::getKeyword() {
  return keyword;
}
vector<string*>* AtRule::getRule() {
  return rule;
}


Stylesheet::~Stylesheet() {
  while (!atrules.empty()) {
    delete atrules.back();
    atrules.pop_back();
  }
  while (!rulesets.empty()) {
    delete rulesets.back();
    rulesets.pop_back();
  }
}

void Stylesheet::addRuleset(Ruleset* ruleset) {
  rulesets.push_back(ruleset);
}

void Stylesheet::addAtRule(AtRule* atrule) {
  atrules.push_back(atrule);
}
vector<AtRule*>* Stylesheet::getAtRules() {
  return &atrules;
}
vector<Ruleset*>* Stylesheet::getRulesets() {
  return &rulesets;
}