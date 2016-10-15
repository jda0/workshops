#include "Arduino.h"

boolean contains(String haystack, String needle) {
         return (haystack.indexOf(needle) != -1);
}
