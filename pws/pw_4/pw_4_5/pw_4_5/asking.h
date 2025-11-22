#pragma once

extern const char CONTINUATION_CHOICE_MSG[];
extern const char YES;
extern const char NO;

bool getChoice(const char* question = CONTINUATION_CHOICE_MSG);