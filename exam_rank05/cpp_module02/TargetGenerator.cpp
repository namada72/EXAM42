#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator() {}

TargetGenerator::~TargetGenerator(){
	for(std::map<std::string,ATarget*>::iterator it = _targets.begin(); it != _targets.end();++it) {
		delete it->second;
	}
	_targets.clear();
}

void TargetGenerator::learnTargetType(ATarget* targettype) {
	if(targettype) {
		std::map<std::string, ATarget*>::iterator it = _targets.find(targettype->getType());
		if (it == _targets.end()) {
			_targets[targettype->getType()] = targettype->clone();
		}
	}
}			

void TargetGenerator::forgetTargetType(std::string const &targettype) {
		std::map<std::string, ATarget*>::iterator it = _targets.find(targettype);
		if (it != _targets.end())
			_targets.erase(it);
}


ATarget* TargetGenerator::createTarget(std::string const &targettype) {
		std::map<std::string, ATarget*>::iterator it = _targets.find(targettype);
		if (it != _targets.end()) {
			return it->second->clone();
		}
		return NULL;

}
