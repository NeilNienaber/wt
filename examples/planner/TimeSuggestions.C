/*
 * Copyright (C) 2010 Emweb bvba, Kessel-Lo, Belgium.
 *
 * See the LICENSE file for terms of use.
 */

#include "TimeSuggestions.h"

#include <stdio.h>

using namespace Wt;

namespace {
  WSuggestionPopup::Options contactOptions
  = { "<b>",         // highlightBeginTag
      "</b>",        // highlightEndTag
      0,           // listSeparator
      " \\n",        // whitespace
      "-., \"@\\n;", // wordSeparators
      ""           // appendReplacedText
    };
}

TimeSuggestions::TimeSuggestions(WContainerWidget* parent)
  : WSuggestionPopup(WSuggestionPopup::generateMatcherJS(contactOptions),
                     WSuggestionPopup::generateReplacerJS(contactOptions),
                     parent)
{
  for (unsigned i = 0; i < 24; i++) {
    char buffer [2];
    sprintf(buffer, "%02d", i);
    std::string h = buffer;
    
    addSuggestion(WString(h + ":00"));
    addSuggestion(WString(h + ":30"));
  }
}

void TimeSuggestions::addSuggestion(const WString& suggestion)
{
  WSuggestionPopup::addSuggestion(suggestion, suggestion);
}