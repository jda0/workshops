#include "Arduino.h"
#include "WebServer.h"

String webPage = "HTTP/1.1 200 OK\r\n"
    "Content-Type: text/html\r\n\r\n"
    "<!DOCTYPE HTML>\n"
    "<style>body{font-size:62.5%;text-align:center;font-family:Verdana;}a{color:#83d3c9;font-size:7rem;}</style>\n"
    "<html>"
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
