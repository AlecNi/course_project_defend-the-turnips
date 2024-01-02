
#ifndef _DATA_TOOL_H
#define _DATA_TOOL_H



#include <cocos2d.h>
struct SLevelData;
USING_NS_CC;

std::vector<int> trans_xy_to_ij(Vec2 vec);
cocos2d::Vec2 trans_ij_to_xy(int ix, int iy);
SLevelData* openFile(const std::string& refFileName);



#endif