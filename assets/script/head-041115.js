//Google Analytics
(function(i,s,o,g,r,a,m){i['GoogleAnalyticsObject']=r;i[r]=i[r]||function(){
    (i[r].q=i[r].q||[]).push(arguments)},i[r].l=1*new Date();a=s.createElement(o),
    m=s.getElementsByTagName(o)[0];a.async=1;a.src=g;m.parentNode.insertBefore(a,m)
})(window,document,'script','//www.google-analytics.com/analytics.js','ga');

ga('create', 'UA-49161384-5', 'auto');
ga('send', 'pageview');

if (window.addEventListener) { // Mozilla, Netscape, Firefox
    window.addEventListener('resize', adjustVideosIframeSize, false);
} else if (window.attachEvent) { // IE
    window.attachEvent('resize', adjustVideosIframeSize);
}

function adjustVideosIframeSize() {
    var iframe = $(".video-iframe");
    iframe.css('width', $(".content-section").width()*0.9 + "px");
    iframe.css('height', iframe.width()*0.563 + "px");
}

$(function() {
	adjustVideosIframeSize();
});