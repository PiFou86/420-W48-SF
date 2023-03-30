// directives et macros
#ifndef DBG_ 
      #define DBG_ true      // false pour masquer les traces   
#endif
#define DBG_STRING_(x) if (DBG_) {Serial.print(x); };
#define DBG_LINENUMBER_\
      if (DBG_) {\
      Serial.print( F("We are at LINE: "));\
      Serial.println(__LINE__);\
      } ;
#define DBG_CONTEXTE_(TexteLitteral, NomVariable)\
      if (DBG_) {\
      Serial.print( F(#TexteLitteral "\t"  #NomVariable"=") ); \
      Serial.println((NomVariable)); \
      } ;
#define DBG_DETAILS_\
      if (DBG_) {\
            Serial.print( F("  compiled :") );\
            Serial.print( F(__DATE__) );\
            Serial.print( F(",") );\
            Serial.print( F(__TIME__) );\
            Serial.print( F(",") );\
            Serial.println( F(__FILE__) );\
      } ;