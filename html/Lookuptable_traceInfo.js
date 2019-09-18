function RTW_Sid2UrlHash() {
	this.urlHashMap = new Array();
	/* <Root>/Tnex */
	this.urlHashMap["Lookuptable:5"] = "Lookuptable.h:117";
	/* <Root>/Beta */
	this.urlHashMap["Lookuptable:7"] = "Lookuptable.h:118";
	/* <Root>/T */
	this.urlHashMap["Lookuptable:18"] = "Lookuptable.h:119";
	/* <Root>/SOC */
	this.urlHashMap["Lookuptable:19"] = "Lookuptable.h:120";
	/* <Root>/2-D Lookup
Table1 */
	this.urlHashMap["Lookuptable:1"] = "Lookuptable.cpp:239,240,281&Lookuptable.h:30,31,32,33,34,35,42,43,44,48,55,60,65,85,90,95&Lookuptable_data.cpp:22,30,35,61,66,71";
	/* <Root>/2-D Lookup
Table2 */
	this.urlHashMap["Lookuptable:8"] = "Lookuptable.cpp:258,259,329&Lookuptable.h:36,37,38,39,40,41,45,46,47,49,70,75,80,100,105,110&Lookuptable_data.cpp:40,51,56,76,81,86";
	/* <Root>/Qt */
	this.urlHashMap["Lookuptable:6"] = "Lookuptable.cpp:255&Lookuptable.h:125";
	/* <Root>/R0 */
	this.urlHashMap["Lookuptable:11"] = "Lookuptable.cpp:274&Lookuptable.h:126";
	this.getUrlHash = function(sid) { return this.urlHashMap[sid];}
}
RTW_Sid2UrlHash.instance = new RTW_Sid2UrlHash();
function RTW_rtwnameSIDMap() {
	this.rtwnameHashMap = new Array();
	this.sidHashMap = new Array();
	this.rtwnameHashMap["<Root>"] = {sid: "Lookuptable"};
	this.sidHashMap["Lookuptable"] = {rtwname: "<Root>"};
	this.rtwnameHashMap["<Root>/Tnex"] = {sid: "Lookuptable:5"};
	this.sidHashMap["Lookuptable:5"] = {rtwname: "<Root>/Tnex"};
	this.rtwnameHashMap["<Root>/Beta"] = {sid: "Lookuptable:7"};
	this.sidHashMap["Lookuptable:7"] = {rtwname: "<Root>/Beta"};
	this.rtwnameHashMap["<Root>/T"] = {sid: "Lookuptable:18"};
	this.sidHashMap["Lookuptable:18"] = {rtwname: "<Root>/T"};
	this.rtwnameHashMap["<Root>/SOC"] = {sid: "Lookuptable:19"};
	this.sidHashMap["Lookuptable:19"] = {rtwname: "<Root>/SOC"};
	this.rtwnameHashMap["<Root>/2-D Lookup Table1"] = {sid: "Lookuptable:1"};
	this.sidHashMap["Lookuptable:1"] = {rtwname: "<Root>/2-D Lookup Table1"};
	this.rtwnameHashMap["<Root>/2-D Lookup Table2"] = {sid: "Lookuptable:8"};
	this.sidHashMap["Lookuptable:8"] = {rtwname: "<Root>/2-D Lookup Table2"};
	this.rtwnameHashMap["<Root>/Qt"] = {sid: "Lookuptable:6"};
	this.sidHashMap["Lookuptable:6"] = {rtwname: "<Root>/Qt"};
	this.rtwnameHashMap["<Root>/R0"] = {sid: "Lookuptable:11"};
	this.sidHashMap["Lookuptable:11"] = {rtwname: "<Root>/R0"};
	this.getSID = function(rtwname) { return this.rtwnameHashMap[rtwname];}
	this.getRtwname = function(sid) { return this.sidHashMap[sid];}
}
RTW_rtwnameSIDMap.instance = new RTW_rtwnameSIDMap();
