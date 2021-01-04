#if defined(__AVR__)
const byte favicon [] PROGMEM_LATE = {
#else
const char favicon [] PROGMEM_LATE = {
#endif
  0x89, 0x50, 0x4e, 0x47, 0x0d, 0x0a, 0x1a, 0x0a, 0x00, 0x00, 0x00, 0x0d, 0x49, 0x48, 0x44, 0x52,
  0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x10, 0x08, 0x02, 0x00, 0x00, 0x00, 0x90, 0x91, 0x68,
  0x36, 0x00, 0x00, 0x00, 0x6c, 0x49, 0x44, 0x41, 0x54, 0x28, 0xcf, 0x95, 0x52, 0x41, 0x0e, 0xc0,
  0x20, 0x08, 0x03, 0xe2, 0xff, 0xbf, 0xcc, 0x0e, 0xdd, 0x18, 0xc1, 0x42, 0x42, 0x0f, 0xa6, 0x54,
  0xc0, 0x8a, 0xaa, 0x7c, 0x70, 0x77, 0x10, 0x55, 0xcd, 0x4a, 0x09, 0x5f, 0x86, 0x20, 0x56, 0xaa,
  0x80, 0x98, 0xf4, 0xf8, 0x5b, 0x26, 0xe8, 0xd6, 0x92, 0xe6, 0x8d, 0xd2, 0x12, 0x4a, 0xe8, 0x20,
  0x93, 0x25, 0x8a, 0x5a, 0x10, 0x06, 0x3a, 0xec, 0xef, 0x40, 0x47, 0x31, 0x59, 0xa2, 0x1e, 0xb2,
  0x58, 0xb8, 0xd1, 0x6c, 0x0c, 0x87, 0xd6, 0x18, 0xcd, 0x86, 0xe3, 0xec, 0x3e, 0xf8, 0x99, 0xfd,
  0xdc, 0x20, 0x05, 0xf7, 0xb8, 0xf2, 0x21, 0x8b, 0x87, 0x43, 0xa3, 0x23, 0xf4, 0x03, 0xf7, 0x78,
  0x00, 0x35, 0x57, 0x66, 0x05, 0xab, 0xf8, 0x2b, 0x0b, 0x00, 0x00, 0x00, 0x00, 0x49, 0x45, 0x4e,
  0x44, 0xae, 0x42, 0x60, 0x82
};

#if !defined(I_WILL_USE_EXTERNAL_INTERFACE) && !defined(I_DO_NOT_NEED_NATIVE_WEB_INTERFACE)
const char graph_html[] PROGMEM_LATE =
"<!--\n"
"/*\n"
"	Based on the awesome tutorials at\n"
"		https://bl.ocks.org/d3noob\n"
"		https://bl.ocks.org/larsenmtl\n"
"	Thanks a lot for your great work!\n"
"*/\n"
"//-->\n"
"<style> /* set the CSS */\n"
"\n"
"path { \n"
"	stroke: steelblue;\n"
"	stroke-width: 2;\n"
"	fill: none;\n"
"}\n"
"\n"
".axis path,\n"
".axis line {\n"
"	fill: none;\n"
"	stroke: grey;\n"
"	stroke-width: 1;\n"
"	shape-rendering: crispEdges;\n"
"}\n"
"\n"
".legend {\n"
"	font-size: 16px;\n"
"	font-weight: bold;\n"
"	text-anchor: middle;\n"
"}\n"
"\n"
"</style>\n"
"<!-- load the d3.js library -->    \n"
"<script src=\"http://d3js.org/d3.v3.min.js\"></script>\n"
"\n"
"<script>\n"
"\n"
"// Set the dimensions of the canvas / graph\n"
"var margin = {top: 30, right: 20, bottom: 70, left: 50},\n"
"width = 1000 - margin.left - margin.right,\n"
"height = 600 - margin.top - margin.bottom;\n"
"\n"
"// Parse the date / time\n"
"var parseDate = d3.time.format(\"%d.%m.%Y %H:%M:%S\").parse;\n"
"\n"
"// Set the ranges\n"
"var x = d3.time.scale().range([0, width]);\n"
"var y = d3.scale.linear().range([height, 0]);\n"
"\n"
"// Define the axes\n"
"var axisTimeFormat = d3.time.format.multi([\n"
"	[\".%L\", function(d) { return d.getMilliseconds(); }],\n"
"	[\":%S\", function(d) { return d.getSeconds(); }],\n"
"	[\"%H:%M\", function(d) { return d.getMinutes(); }],\n"
"	[\"%H:%M\", function(d) { return d.getHours(); }],\n"
"	[\"%d.%m\", function(d) { return d.getDay() && d.getDate() != 1; }],\n"
"	[\"%m.%Y\", function(d) { return d.getDate() != 1; }],\n"
"	[\"%B\", function(d) { return d.getMonth(); }],\n"
"	[\"%Y\", function() { return true; }]\n"
" ]);\n"
"\n"
"var xAxis = d3.svg.axis().scale(x)\n"
"		.orient(\"bottom\").ticks(5)\n"
"		.tickFormat(axisTimeFormat);\n"
"\n"
"var yAxis = d3.svg.axis().scale(y)\n"
"		.orient(\"left\").ticks(5);\n"
"\n"
"// Define the line\n"
"var priceline = d3.svg.line()	\n"
"	.x(function(d) { return x(d.Date); })\n"
"	.y(function(d) { return y(d.Value); });\n"
"    \n"
"// Get the data\n"
"var dsv = d3.dsv(\";\", \"text/plain\");\n"
"dsv(\"D\", function(data) {\n"
"\n"
"	data.forEach(function(d) {\n"
"		d.Date = parseDate(d.Date);\n"
"		d.Value = +d.Value;\n"
"    	});\n"
"\n"
"	// Scale the range of the data\n"
"	x.domain(d3.extent(data, function(d) { return d.Date; }));\n"
"	y.domain([0, d3.max(data, function(d) { return d.Value; })]);\n"
"\n"
"    	// Nest the entries by symbol\n"
"    	var dataNest = d3.nest()\n"
"        	.key(function(d) {return d.Description;})\n"
"        	.entries(data);\n"
"\n"
"// Adds the svg canvas\n"
"var svg = d3.select(\"div\")\n"
"    .append(\"svg\")\n"
"     .attr(\"width\", width + margin.left + margin.right)\n"
"     .attr(\"height\", height + margin.top + margin.bottom + dataNest.length/4 * 15)\n"
"   .append(\"g\")\n"
"     .attr(\"transform\", \"translate(\" + margin.left + \",\" + margin.top + \")\");\n"
"\n"
"	var color = d3.scale.category10();   // set the colour scale\n"
"\n"
"	legendSpace = width/dataNest.length; // spacing for the legend\n"
"\n"
"	// Loop through each symbol / key\n"
"	dataNest.forEach(function(d,i) { \n"
"\n"
"		svg.append(\"path\")\n"
"        		.attr(\"class\", \"line\")\n"
"        		.style(\"stroke\", function() { // Add the colours dynamically\n"
"                		return d.color = color(d.key); })\n"
"			.attr(\"id\", 'tag'+d.key.replace(/\\s+/g, '')) // assign ID\n"
"			.attr(\"d\", priceline(d.values));\n"
"\n"
"		// Add the Legend\n"
"		svg.append(\"text\")\n"
"            		.attr(\"x\", (margin.left + legendSpace/2 + (i % 4) * width / 4))  // space legend\n"
"            		.attr(\"y\", height + (margin.bottom/2)+ 5 + Math.floor(i/4)*20)\n"
"            		.attr(\"class\", \"legend\")    // style the legend\n"
"            		.style(\"fill\", function() { // Add the colours dynamically\n"
"                		return d.color = color(d.key); })\n"
"			.on(\"click\", function(){\n"
"				// Determine if current line is visible \n"
"				var active   = d.active ? false : true,\n"
"				newOpacity = active ? 0 : 1; \n"
"				// Hide or show the elements based on the ID\n"
"				d3.select(\"#tag\"+d.key.replace(/\\s+/g, ''))\n"
"					.transition().duration(100) \n"
"					.style(\"opacity\", newOpacity); \n"
"				// Update whether or not the elements are active\n"
"				d.active = active;\n"
"			})\n"
"			.text(d.key); \n"
"	});\n"
"\n"
"	var mouseG = svg.append(\"g\")\n"
"	.attr(\"class\", \"mouse-over-effects\");\n"
"\n"
"	mouseG.append(\"path\") // this is the black vertical line to follow mouse\n"
"		.attr(\"class\", \"mouse-line\")\n"
"		.style(\"stroke\", \"black\")\n"
"		.style(\"stroke-width\", \"1px\")\n"
"		.style(\"opacity\", \"0\");\n"
"\n"
"	var lines = document.getElementsByClassName('line');\n"
"\n"
"	var mousePerLine = mouseG.selectAll('.mouse-per-line')\n"
"		.data(dataNest)\n"
"		.enter()\n"
"		.append(\"g\")\n"
"		.attr(\"class\", \"mouse-per-line\");\n"
"\n"
"	mousePerLine.append(\"circle\")\n"
"		.attr(\"r\", 7)\n"
"		.attr(\"id\", function(d) {\n"
"			return 'tag'+d.key.replace(/\\s+/g, '')	// assign ID\n"
"		})\n"
"		.style(\"stroke\", function(d) {\n"
"			return color(d.key);\n"
"		})\n"
"		.style(\"fill\", \"none\")\n"
"		.style(\"stroke-width\", \"1px\")\n"
"		.style(\"opacity\", \"0\");\n"
"\n"
"	mousePerLine.append(\"text\")\n"
"		.attr(\"id\", function(d) {\n"
"			return 'tag'+d.key.replace(/\\s+/g, '')	// assign ID\n"
"		})\n"
"		.attr(\"transform\", \"translate(10,3)\");\n"
"\n"
"	mouseG.append('svg:rect') // append a rect to catch mouse movements on canvas\n"
"		.attr('width', width) // can't catch mouse events on a g element\n"
"		.attr('height', height)\n"
"		.attr('fill', 'none')\n"
"		.attr('pointer-events', 'all')\n"
"		.on('mouseout', function() { // on mouse out hide line, circles and text\n"
"			d3.select(\".mouse-line\")\n"
"				.style(\"opacity\", \"0\");\n"
"			d3.selectAll(\".mouse-per-line circle\")\n"
"				.style(\"opacity\", \"0\");\n"
"			d3.selectAll(\".mouse-per-line text\")\n"
"				.style(\"opacity\", \"0\");\n"
"		})\n"
"		.on('mouseover', function() { // on mouse in show line, circles and text\n"
"			d3.select(\".mouse-line\")\n"
"				.style(\"opacity\", \"1\");\n"
"			d3.selectAll(\".mouse-per-line circle\")\n"
"				.style(\"opacity\", function(d) {\n"
"					return d.active ? 0 : 1;;\n"
"				});\n"
"			d3.selectAll(\".mouse-per-line text\")\n"
"				.style(\"opacity\", function(d) {\n"
"					return d.active ? 0 : 1;;\n"
"				});\n"
"		})\n"
"		.on('mousemove', function() { // mouse moving over canvas\n"
"			var mouse = d3.mouse(this);\n"
"			d3.select(\".mouse-line\")\n"
"				.attr(\"d\", function() {\n"
"					var d = \"M\" + mouse[0] + \",\" + height;\n"
"					d += \" \" + mouse[0] + \",\" + 0;\n"
"					return d;\n"
"				});\n"
"\n"
"			d3.selectAll(\".mouse-per-line\")\n"
"				.attr(\"transform\", function(d, i) {\n"
"					var xDate = x.invert(mouse[0]),\n"
"					bisect = d3.bisector(function(d) { return d.Date; }).right;\n"
"					idx = bisect(d.values, xDate);\n"
"\n"
"					var beginning = 0,\n"
"					end = lines[i].getTotalLength(),\n"
"					target = null;\n"
"\n"
"					while (true){\n"
"						target = Math.floor((beginning + end) / 2);\n"
"						pos = lines[i].getPointAtLength(target);\n"
"						if ((target === end || target === beginning) && pos.x !== mouse[0]) {\n"
"							break;\n"
"						}\n"
"						if (pos.x > mouse[0]) end = target;\n"
"						else if (pos.x < mouse[0]) beginning = target;\n"
"						else break; //position found\n"
"					}\n"
"\n"
"					outputFormat = d3.time.format(\"%H:%M:%S\");\n"
"					d3.select(this).select('text')\n"
"					.text(d.values[idx].Value + \" (\" + outputFormat(d.values[idx].Date) + \")\");\n"
"\n"
"					return \"translate(\" + mouse[0] + \",\" + pos.y +\")\";\n"
"				});\n"
"	});\n"
"\n"
"	// Add the X Axis\n"
"	svg.append(\"g\")\n"
"		.attr(\"class\", \"x axis\")\n"
"		.attr(\"transform\", \"translate(0,\" + height + \")\")\n"
"		.call(xAxis);\n"
"\n"
"	// Add the Y Axis\n"
"	svg.append(\"g\")\n"
"		.attr(\"class\", \"y axis\")\n"
"		.call(yAxis);\n"
"\n"
"});\n"
"\n"
"</script>\n";
#endif

const char header_html[] PROGMEM_LATE =
  "\n"
  "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.01//EN\">\n"
  "<html><head>\n"
  "<meta http-equiv=\"content-type\" content=\"text/html; charset=UTF-8\">\n"
  "<meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0,  minimum-scale=1.0\">\n"
  "<title>BSB-LAN Web</title>\n"
  "<style>A:link  {color:blue;text-decoration: none;} A:visited {color:blue;text-decoration: none;} A:hover {color:red;text-decoration: none;background-color:yellow} A:active {color:blue;text-decoration: none;} A:focus {color:red;text-decoration: none;}\n"
  "table {width: 100%;  max-width: 1024px;  margin: auto;}\n"
  "td {vertical-align: top;}\n"
  "td.header {vertical-align: middle;}\n"
  "input {width: 100%; box-sizing: border-box;} select {width: 100%;}</style>\n"
  "</head><body>\n";
const char header_html2[] PROGMEM_LATE =
  "<script>function set(line){\n"
  "var value = document.getElementById('value'+line).value.replace(/\\.$/, '');\n"
  "value = value.replace(':', '.');\n"
  "value = value.replace('---', '');\n"
  "if(isNaN(value)==false || value == ''){\n"
  "window.open(document.getElementById('main_link').href+'S'+line+'='+value,'_self');\n"
  "}}\n"
  "function setbit(line){\n"
  "var x=document.getElementById('value'+line); var value=0;\n"
  "for (var i=0; i<x.options.length; i++) {\n"
  "if(x.options[i].selected){\n"
  "value=value+eval(x.options[i].value);\n"
  "}}\n"
  "window.open(document.getElementById('main_link').href+'S'+line+'='+value,'_self');\n"
  "}</script>\n";
const char header_html3[] PROGMEM_LATE =
  "<font face='Arial'>\n"
  "<center><h1>";

const char auth_req_html[] PROGMEM_LATE =
  "WWW-Authenticate: Basic realm=\"Secure Area\"\n"
  "Connnection: close\n"
  "\n"
  "<!DOCTYPE HTML>\n"
  "<HTML><HEAD><TITLE>Error</TITLE>\n"
  "</HEAD> <BODY><H1>401 Unauthorized.</H1></BODY></HTML>\n";
