// directives et macros
#ifndef DEBUG_ 
      #define DEBUG_ true      // false pour masquer les traces   
#endif
#define DEBUG_STRING_(x) if (DEBUG_) {Serial.print(x); };
#define DEBUG_LINENUMBER_\
      if (DEBUG_) {\
      Serial.print( F("We are at LINE: "));\
      Serial.println(__LINE__);\
      } ;
#define DEBUG_CONTEXTE_(TexteLitteral, NomVariable)\
      if (DEBUG_) {\
      Serial.print( F(#TexteLitteral "\t"  #NomVariable"=") ); \
      Serial.println((NomVariable)); \
      } ;
#define DEBUG_DETAILS_\
      if (DEBUG_) {\
            Serial.print( F("  compiled :") );\
            Serial.print( F(__DATE__) );\
            Serial.print( F(",") );\
            Serial.print( F(__TIME__) );\
            Serial.print( F(",") );\
            Serial.println( F(__FILE__) );\
      } ;