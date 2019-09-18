function CodeDefine() { 
this.def = new Array();
this.def["rtObj"] = {file: "ert_main_cpp.html",line:22,type:"var"};
this.def["rt_OneStep"] = {file: "ert_main_cpp.html",line:36,type:"fcn"};
this.def["main"] = {file: "ert_main_cpp.html",line:72,type:"fcn"};
this.def["rt_Spline2Derivd"] = {file: "Lookuptable_cpp.html",line:33,type:"fcn"};
this.def["look_SplNLinSZd"] = {file: "Lookuptable_cpp.html",line:63,type:"fcn"};
this.def["intrp_NSpld"] = {file: "Lookuptable_cpp.html",line:88,type:"fcn"};
this.def["plook_linx"] = {file: "Lookuptable_cpp.html",line:192,type:"fcn"};
this.def["linsearch_u32d"] = {file: "Lookuptable_cpp.html",line:218,type:"fcn"};
this.def["step"] = {file: "Lookuptable_cpp.html",line:234,type:"fcn"};
this.def["initialize"] = {file: "Lookuptable_cpp.html",line:279,type:"fcn"};
this.def["DW"] = {file: "Lookuptable_h.html",line:50,type:"type"};
this.def["ConstP"] = {file: "Lookuptable_h.html",line:113,type:"type"};
this.def["ExtU"] = {file: "Lookuptable_h.html",line:121,type:"type"};
this.def["ExtY"] = {file: "Lookuptable_h.html",line:127,type:"type"};
this.def["rtU"] = {file: "Lookuptable_h.html",line:148,type:"var"};
this.def["rtConstP"] = {file: "Lookuptable_data_cpp.html",line:20,type:"var"};
this.def["int8_T"] = {file: "rtwtypes_h.html",line:49,type:"type"};
this.def["uint8_T"] = {file: "rtwtypes_h.html",line:50,type:"type"};
this.def["int16_T"] = {file: "rtwtypes_h.html",line:51,type:"type"};
this.def["uint16_T"] = {file: "rtwtypes_h.html",line:52,type:"type"};
this.def["int32_T"] = {file: "rtwtypes_h.html",line:53,type:"type"};
this.def["uint32_T"] = {file: "rtwtypes_h.html",line:54,type:"type"};
this.def["real32_T"] = {file: "rtwtypes_h.html",line:55,type:"type"};
this.def["real64_T"] = {file: "rtwtypes_h.html",line:56,type:"type"};
this.def["real_T"] = {file: "rtwtypes_h.html",line:62,type:"type"};
this.def["time_T"] = {file: "rtwtypes_h.html",line:63,type:"type"};
this.def["boolean_T"] = {file: "rtwtypes_h.html",line:64,type:"type"};
this.def["int_T"] = {file: "rtwtypes_h.html",line:65,type:"type"};
this.def["uint_T"] = {file: "rtwtypes_h.html",line:66,type:"type"};
this.def["ulong_T"] = {file: "rtwtypes_h.html",line:67,type:"type"};
this.def["char_T"] = {file: "rtwtypes_h.html",line:68,type:"type"};
this.def["uchar_T"] = {file: "rtwtypes_h.html",line:69,type:"type"};
this.def["byte_T"] = {file: "rtwtypes_h.html",line:70,type:"type"};
this.def["pointer_T"] = {file: "rtwtypes_h.html",line:88,type:"type"};
}
CodeDefine.instance = new CodeDefine();
var testHarnessInfo = {OwnerFileName: "", HarnessOwner: "", HarnessName: "", IsTestHarness: "0"};
var relPathToBuildDir = "../ert_main.c";
var fileSep = "\\";
var isPC = true;
function Html2SrcLink() {
	this.html2SrcPath = new Array;
	this.html2Root = new Array;
	this.html2SrcPath["ert_main_cpp.html"] = "../ert_main.cpp";
	this.html2Root["ert_main_cpp.html"] = "ert_main_cpp.html";
	this.html2SrcPath["Lookuptable_cpp.html"] = "../Lookuptable.cpp";
	this.html2Root["Lookuptable_cpp.html"] = "Lookuptable_cpp.html";
	this.html2SrcPath["Lookuptable_h.html"] = "../Lookuptable.h";
	this.html2Root["Lookuptable_h.html"] = "Lookuptable_h.html";
	this.html2SrcPath["Lookuptable_data_cpp.html"] = "../Lookuptable_data.cpp";
	this.html2Root["Lookuptable_data_cpp.html"] = "Lookuptable_data_cpp.html";
	this.html2SrcPath["rtwtypes_h.html"] = "../rtwtypes.h";
	this.html2Root["rtwtypes_h.html"] = "rtwtypes_h.html";
	this.getLink2Src = function (htmlFileName) {
		 if (this.html2SrcPath[htmlFileName])
			 return this.html2SrcPath[htmlFileName];
		 else
			 return null;
	}
	this.getLinkFromRoot = function (htmlFileName) {
		 if (this.html2Root[htmlFileName])
			 return this.html2Root[htmlFileName];
		 else
			 return null;
	}
}
Html2SrcLink.instance = new Html2SrcLink();
var fileList = [
"ert_main_cpp.html","Lookuptable_cpp.html","Lookuptable_h.html","Lookuptable_data_cpp.html","rtwtypes_h.html"];
