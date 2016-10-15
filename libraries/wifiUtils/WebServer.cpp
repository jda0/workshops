#include "Arduino.h"
#include "WebServer.h"

String webPage = "HTTP/1.1 200 OK\r\n"
    "Content-Type: text/html\r\n\r\n"
    "<!DOCTYPE HTML>\n"
    "<style>body{font-size:62.5%;text-align:center;font-family:Verdana;}a{color:#83d3c9;font-size:7rem;}</style>\n"
    "<html>"
    "<script>"
    // up    = 38
    // down  = 40
    // left  = 37
    // right = 39
    "function movementKeys(e) {\n"
    "    var up    = 38\n"
    "    var down  = 40\n"
    "    var left  = 37\n"
    "    var right = 39\n"
    "    switch(e.keyCode) {\n"
    "        case up:\n"
    "           location = window.location.host + '/' + 'forward'\n"
    "           break\n"
    "        case down:\n"
    "           location = window.location.host + '/' + 'reverse'\n"
    "           break\n"
    "        case left:\n"
    "           location = window.location.host + '/' + 'left'\n"
    "           break\n"
    "        case right:\n"
    "           location = window.location.host + '/' + 'right'\n"
    "           break\n"
    "        default:\n"
    "           location = window.location.host + '/' + 'stop'\n"
    "    }\n"
    "}\n"
    "document.addEventListener('keydown', movementKeys)\n"
    "</script>"
    "<a href=/forward>&#8593;</a><br><br>"
    "<a href=/left style='margin-right:50px'>&#8592;</a><a href=/stop>&#9632;</a><a href=/right style='margin-left:50px'>&#8594;</a><br><br>"
    "<a href=/reverse>&#8595;</a><br><br><br><br>"
    "<br><br><br><br><br>"
    "<a href=/smile style='margin-right:100px;'>:)</a>"
    "<a href=/frown style='margin-right:100px;'>:(</a>"
    "<a href=/wink>;)</a>"
    "</html>\n";

String getWebPageHtml(void) {
    return webPage;
}
