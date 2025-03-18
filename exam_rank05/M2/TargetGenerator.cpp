#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator() {
	//std::cout << _name << ": This looks like another boring day." << std::endl;	
}

TargetGenerator::~TargetGenerator(){
	//std::cout << _name << ": My job here is done!" << std::endl;
	//libero memoria hechizos aprendidos
	for(std::map<std::string, ATarget*>::iterator it = _targets.begin(); it != _targets.end(); ++it){
	delete it->second;
	}
	_targets.clear();
}

//const std::string & TargetGenerator::getName() const{ return _name; }
		
//const std::string & TargetGenerator::getTitle() const { return _title; }

//void TargetGenerator::setTitle(std::string const &newtitle) {_title = newtitle; }

// void TargetGenerator::introduce() const{
// std::cout << _name << ": I am " << _name << ", " << _title << "!" << std::endl;
// }

void TargetGenerator::learnTargetType(ATarget *target){
	if(target)
	{
		if((_targets.find(target->getType())) == _targets.end()) {
			_targets[target->getType()] = target->clone();
		}
	}
}


void TargetGenerator::forgetTargetType(std::string const &targetType){
	std::map<std::string, ATarget*>::iterator it = _targets.find(targetType);
	if (it !=_targets.end()) {
		//delete it->second;
		_targets.erase(it);
	}
}

// void TargetGenerator::launchSpell(std::string spellName, ATarget const &target){
	
// 	std::map<std::string, ASpell*>::iterator it = _spells.find(spellName);
// 	if (it !=_spells.end() ){
// 		it->second->launch(target);
// 	}
// }

ATarget* TargetGenerator::createTarget(std::string const &targetType) {
	std::map<std::string, ATarget*>::iterator it = _targets.find(targetType);
	if (it != _targets.end()) {
		return it->second->clone();
	}
	return NULL;
}
