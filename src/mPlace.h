#ifndef __MACRO_PLACE__
#define __MACRO_PLACE__

#include "partition.h"

class MacroCircuit;
class CircuitInfo;
class EnvFile;

namespace Circuit{
  class Circuit;
}

std::vector<std::pair<MacroNetlist::Partition, MacroNetlist::Partition>> GetPart ( 
    CircuitInfo& cInfo,  
    MacroNetlist::Partition& partition, bool isHorizontal );

// Partition Class --> macroStor's index.
void UpdateMacroPartMap( MacroCircuit& mckt,
    MacroNetlist::Partition& part, 
        std::unordered_map< MacroNetlist::PartClass, std::vector<int>,
        MyHash<MacroNetlist::PartClass>>& macroPartMap);

std::vector< std::vector<MacroNetlist::Partition> > 
PlaceMacros(EnvFile& env, Circuit::Circuit& ckt, MacroCircuit& mckt);

void UpdateCircuitCoordi(EnvFile& env, MacroCircuit& mckt, Circuit::Circuit& ckt);


#endif
