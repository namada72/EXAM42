#pragma once

#include <iostream>
#include <string>
#include <map>
#include "ATarget.hpp"

class TargetGenerator {
	private:
	
		TargetGenerator(TargetGenerator const &src);
	
		TargetGenerator &operator=(TargetGenerator const &src);

		std::map<std::string,ATarget*> _targets;
	
	public:
		TargetGenerator();
		~TargetGenerator();

//		const std::string & getName() const;
//		const std::string & getTitle() const;

//		void setTitle(std::string const &newtitle);

//		void introduce() const;

		void learnTargetType(ATarget* target);
		void forgetTargetType(std::string const &targetType);
//		void launchSpell(std::string spellName, ATarget const &target);

		ATarget* createTarget(std::string const &targetType);

};


