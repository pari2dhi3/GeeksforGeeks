(function(){var r=this,aa=function(a){var b=typeof a;return"object"==b&&null!=a||"function"==b},ba=function(a,b,c){return a.call.apply(a.bind,arguments)},ca=function(a,b,c){if(!a)throw Error();if(2<arguments.length){var d=Array.prototype.slice.call(arguments,2);return function(){var c=Array.prototype.slice.call(arguments);Array.prototype.unshift.apply(c,d);return a.apply(b,c)}}return function(){return a.apply(b,arguments)}},t=function(a,b,c){t=Function.prototype.bind&&-1!=Function.prototype.bind.toString().indexOf("native code")?
ba:ca;return t.apply(null,arguments)},da=function(a,b){function c(){}c.prototype=b.prototype;a.Ia=b.prototype;a.prototype=new c;a.Ha=function(a,c,g){for(var f=Array(arguments.length-2),h=2;h<arguments.length;h++)f[h-2]=arguments[h];return b.prototype[c].apply(a,f)}};var ea=(new Date).getTime();var fa=String.prototype.trim?function(a){return a.trim()}:function(a){return a.replace(/^[\s\xa0]+|[\s\xa0]+$/g,"")},ga=/&/g,ia=/</g,ja=/>/g,ka=/"/g,la=/'/g,ma=/\x00/g,na={"\x00":"\\0","\b":"\\b","\f":"\\f","\n":"\\n","\r":"\\r","\t":"\\t","\x0B":"\\x0B",'"':'\\"',"\\":"\\\\"},oa={"'":"\\'"},pa=function(a,b){return a<b?-1:a>b?1:0};var qa=function(a,b){this.start=a<b?a:b;this.end=a<b?b:a};var ra=function(a,b){this.width=a;this.height=b};ra.prototype.floor=function(){this.width=Math.floor(this.width);this.height=Math.floor(this.height);return this};ra.prototype.round=function(){this.width=Math.round(this.width);this.height=Math.round(this.height);return this};var u=function(a){u[" "](a);return a};u[" "]=function(){};var sa=function(a,b,c){a.addEventListener?a.addEventListener(b,c,!1):a.attachEvent&&a.attachEvent("on"+b,c)};var v=function(a){try{var b;if(b=!!a&&null!=a.location.href)a:{try{u(a.foo);b=!0;break a}catch(c){}b=!1}return b}catch(c){return!1}},ta=function(){var a=window;return v(a.top)?a.top:null},w=function(a,b){return b.getComputedStyle?b.getComputedStyle(a,null):a.currentStyle},z=function(a,b){if(!(1E-4>Math.random())){var c=Math.random();if(c<b)return c=ua(window),a[Math.floor(c*a.length)]}return null},ua=function(a){try{var b=new Uint32Array(1);a.crypto.getRandomValues(b);return b[0]/65536/65536}catch(c){return Math.random()}},
va=function(a,b){for(var c in a)Object.prototype.hasOwnProperty.call(a,c)&&b.call(void 0,a[c],c,a)},wa=/^([0-9.]+)px$/,xa=/^(-?[0-9.]{1,30})$/,ya=function(a){return xa.test(a)&&(a=Number(a),!isNaN(a))?a:null},za=function(a){return(a=wa.exec(a))?+a[1]:null};var Aa=function(){var a=A,b;try{b=parseInt(a.localStorage.getItem("google_experiment_mod"),10)}catch(c){return null}if(0<=b&&1E3>b)return b;b=Math.floor(1E3*ua(a));try{return a.localStorage.setItem("google_experiment_mod",""+b),b}catch(c){return null}};var Da=function(a,b,c,d,e,g){try{if((d?a.ca:Math.random())<(e||a.U)){var f=a.T+b+Ba(c),f=f.substring(0,2E3);"undefined"===typeof g?Ca(f):Ca(f,g)}}catch(h){}},Ba=function(a){var b="";va(a,function(a,d){if(0===a||a)b+="&"+d+"="+encodeURIComponent(String(a))});return b},Ca=function(a,b){r.google_image_requests||(r.google_image_requests=[]);var c=r.document.createElement("img");if(b){var d=function(a){b(a);a=d;c.removeEventListener?c.removeEventListener("load",a,!1):c.detachEvent&&c.detachEvent("onload",
a);a=d;c.removeEventListener?c.removeEventListener("error",a,!1):c.detachEvent&&c.detachEvent("onerror",a)};sa(c,"load",d);sa(c,"error",d)}c.src=a;r.google_image_requests.push(c)};var Ea=function(a,b,c){this.$=a;this.W=b;this.P=c;this.J=null;this.V=this.u;this.ia=!1},Fa=function(a,b,c){this.message=a;this.fileName=b||"";this.lineNumber=c||-1},Ha=function(a,b,c,d,e){var g;try{g=c()}catch(k){var f=a.P;try{var h=Ga(k),f=(e||a.V).call(a,b,h,void 0,d)}catch(l){a.u("pAR",l)}if(!f)throw k;}finally{}return g},Ia=function(a,b){var c=C;return function(){var d=arguments;return Ha(c,a,function(){return b.apply(void 0,d)},void 0)}};
Ea.prototype.u=function(a,b,c,d,e){var g={};g.context=a;b instanceof Fa||(b=Ga(b));g.msg=b.message.substring(0,512);b.fileName&&(g.file=b.fileName);0<b.lineNumber&&(g.line=b.lineNumber.toString());a=r.document;g.url=a.URL.substring(0,512);g.ref=a.referrer.substring(0,512);Ja(this,g,d);Da(this.$,e||this.W,g,this.ia,c);return this.P};
var Ja=function(a,b,c){if(a.J)try{a.J(b)}catch(d){}if(c)try{c(b)}catch(d){}},Ga=function(a){var b=a.toString();a.name&&-1==b.indexOf(a.name)&&(b+=": "+a.name);a.message&&-1==b.indexOf(a.message)&&(b+=": "+a.message);if(a.stack){var c=a.stack,d=b;try{-1==c.indexOf(d)&&(c=d+"\n"+c);for(var e;c!=e;)e=c,c=c.replace(/((https?:\/..*\/)[^\/:]*:\d+(?:.|\n)*)\2/,"$1");b=c.replace(/\n */g,"\n")}catch(g){b=d}}return new Fa(b,a.fileName,a.lineNumber)};var D;a:{var Ka=r.navigator;if(Ka){var La=Ka.userAgent;if(La){D=La;break a}}D=""}var G=function(a){return-1!=D.indexOf(a)};var Ma=G("Opera")||G("OPR"),H=G("Trident")||G("MSIE"),Na=G("Edge"),Oa=G("Gecko")&&!(-1!=D.toLowerCase().indexOf("webkit")&&!G("Edge"))&&!(G("Trident")||G("MSIE"))&&!G("Edge"),Pa=-1!=D.toLowerCase().indexOf("webkit")&&!G("Edge"),Qa=function(){var a=D;if(Oa)return/rv\:([^\);]+)(\)|;)/.exec(a);if(Na)return/Edge\/([\d\.]+)/.exec(a);if(H)return/\b(?:MSIE|rv)[: ]([^\);]+)(\)|;)/.exec(a);if(Pa)return/WebKit\/(\S+)/.exec(a)},Ra=function(){var a=r.document;return a?a.documentMode:void 0},Sa=function(){if(Ma&&
r.opera){var a;var b=r.opera.version;try{a=b()}catch(c){a=b}return a}a="";(b=Qa())&&(a=b?b[1]:"");return H&&(b=Ra(),b>parseFloat(a))?String(b):a}(),Ta={},Ua=function(a){if(!Ta[a]){for(var b=0,c=fa(String(Sa)).split("."),d=fa(String(a)).split("."),e=Math.max(c.length,d.length),g=0;0==b&&g<e;g++){var f=c[g]||"",h=d[g]||"",k=RegExp("(\\d*)(\\D*)","g"),l=RegExp("(\\d*)(\\D*)","g");do{var m=k.exec(f)||["","",""],n=l.exec(h)||["","",""];if(0==m[0].length&&0==n[0].length)break;b=pa(0==m[1].length?0:parseInt(m[1],
10),0==n[1].length?0:parseInt(n[1],10))||pa(0==m[2].length,0==n[2].length)||pa(m[2],n[2])}while(0==b)}Ta[a]=0<=b}},Va=r.document,Wa=Va&&H?Ra()||("CSS1Compat"==Va.compatMode?parseInt(Sa,10):5):void 0;var Xa;if(!(Xa=!Oa&&!H)){var Ya;if(Ya=H)Ya=9<=Wa;Xa=Ya}Xa||Oa&&Ua("1.9.1");H&&Ua("9");var Za=document,A=window;var $a=function(a,b){for(var c in a)Object.prototype.hasOwnProperty.call(a,c)&&b.call(null,a[c],c,a)},ab=function(a){return!!a&&"function"==typeof a&&!!a.call},bb=function(a,b){if(!(2>arguments.length))for(var c=1,d=arguments.length;c<d;++c)a.push(arguments[c])},J=function(a,b){if(a.indexOf){var c=a.indexOf(b);return 0<c||0===c}for(c=0;c<a.length;c++)if(a[c]===b)return!0;return!1},cb=function(a){sa(Za,"DOMContentLoaded",a)},db=function(a){a.google_unique_id?++a.google_unique_id:a.google_unique_id=
1},eb=function(a){a=a.google_unique_id;return"number"==typeof a?a:0},fb=function(a){var b=a.length;if(0==b)return 0;for(var c=305419896,d=0;d<b;d++)c^=(c<<5)+(c>>2)+a.charCodeAt(d)&4294967295;return 0<c?c:4294967296+c},gb=!!window.google_async_iframe_id,hb=/(^| )adsbygoogle($| )/;var ib,C,jb="http"+("http:"==A.location.protocol?"":"s")+"://pagead2.googlesyndication.com/pagead/gen_204?id=";ib=new function(){this.T=jb;this.U=.01;this.ca=Math.random()};C=new Ea(ib,"jserror",!0);var kb=function(a,b,c,d){Ha(C,a,c,d,b)},lb=C.u,mb=function(a,b){return Ia(a,b)},nb=function(a){return Ia("aa:reactiveTag",a)};var ob=null,pb=function(){if(!ob){for(var a=window,b=a,c=0;a&&a!=a.parent;)if(a=a.parent,c++,v(a))b=a;else break;ob=b}return ob};var K={Fa:{j:"453848100",i:"453848101"},sa:{j:"828064124",i:"828064125"},ra:{j:"828064127",i:"828064128"},ta:{j:"828064170",i:"828064171"},la:{j:"453848130",i:"453848131",Da:"453848132",Ea:"453848133"},va:{j:"24819308",i:"24819309",ka:"24819320"},ua:{j:"24819330",i:"24819331"},xa:{j:"828064162",i:"828064163"},wa:{j:"828064164",i:"828064165",na:"828064166"},pa:{j:"86724438",i:"86724439"},qa:{j:"828064190",i:"828064191"},za:{j:"10573505",i:"10573506"},D:{j:"10573595",i:"10573596"},Ca:{j:"10573511",
i:"10573512"},F:{j:"10573581",i:"10573582"},Aa:{j:"10573531",i:"10573532"},v:{j:"10573561",i:"10573562"},Ba:{j:"10573551",i:"10573552"},ya:{j:"312815000",i:"312815001"},C:{j:"312815100",i:"312815101"},ma:{j:"26835101",i:"26835102"},oa:{j:"35923720",i:"35923721"},G:{j:"35923760",i:"35923761"},Ga:{j:"27415001",i:"27415002"},H:{j:"20040000",i:"20040001"}};var M=function(a){a=parseFloat(a);return isNaN(a)||1<a||0>a?0:a},qb=function(a,b){var c=parseInt(a,10);return isNaN(c)?b:c},rb=function(a,b){return/^true$/.test(a)?!0:/^false$/.test(a)?!1:b},sb=/^([\w-]+\.)*([\w-]{2,})(\:[0-9]+)?$/,tb=function(a,b){if(!a)return b;var c=a.match(sb);return c?c[0]:b};var ub=M("0.15"),vb=qb("101",-1),wb=qb("10",0),xb=M("0.05"),yb=M("0.001"),zb=M("0.0"),Ab=M(""),Bb=M("0.001"),Cb=rb("true",!0),Eb=M(""),Fb=M("0.001"),
Gb=M(""),Hb=M("0.01");var Ib=rb("false",!1),Jb=rb("false",!1),Kb=Jb||!Ib;var Lb=function(){},Nb=function(a,b,c){switch(typeof b){case "string":Mb(b,c);break;case "number":c.push(isFinite(b)&&!isNaN(b)?b:"null");break;case "boolean":c.push(b);break;case "undefined":c.push("null");break;case "object":if(null==b){c.push("null");break}if(b instanceof Array||void 0!=b.length&&b.splice){var d=b.length;c.push("[");for(var e="",g=0;g<d;g++)c.push(e),Nb(a,b[g],c),e=",";c.push("]");break}c.push("{");d="";for(e in b)b.hasOwnProperty(e)&&(g=b[e],"function"!=typeof g&&(c.push(d),Mb(e,
c),c.push(":"),Nb(a,g,c),d=","));c.push("}");break;case "function":break;default:throw Error("Unknown type: "+typeof b);}},Ob={'"':'\\"',"\\":"\\\\","/":"\\/","\b":"\\b","\f":"\\f","\n":"\\n","\r":"\\r","\t":"\\t","\x0B":"\\u000b"},Pb=/\uffff/.test("\uffff")?/[\\\"\x00-\x1f\x7f-\uffff]/g:/[\\\"\x00-\x1f\x7f-\xff]/g,Mb=function(a,b){b.push('"');b.push(a.replace(Pb,function(a){if(a in Ob)return Ob[a];var b=a.charCodeAt(0),e="\\u";16>b?e+="000":256>b?e+="00":4096>b&&(e+="0");return Ob[a]=e+b.toString(16)}));
b.push('"')};var Qb=null,Rb=Oa||Pa||Ma||"function"==typeof r.atob;var Sb={google_ad_modifications:!0,google_analytics_domain_name:!0,google_analytics_uacct:!0},Tb=function(a){a.google_page_url&&(a.google_page_url=String(a.google_page_url));var b=[];$a(a,function(a,d){if(null!=a){var e;try{var g=[];Nb(new Lb,a,g);e=g.join("")}catch(f){}e&&(e=e.replace(/\//g,"\\$&"),bb(b,d,"=",e,";"))}});return b.join("")};var Ub={overlays:1,interstitials:2,vignettes:2,inserts:3,immersives:4};var N=function(a){a=a.document;return("CSS1Compat"==a.compatMode?a.documentElement:a.body)||{}};var Vb=function(a,b,c){kb("files::getSrc",lb,function(){if("https:"==A.location.protocol&&"http"==c)throw c="https",Error("Requested url "+a+b);});return[c,"://",a,b].join("")},Wb=function(a,b,c){c||(c=Kb?"https":"http");return Vb(a,b,c)};var Xb=new function(){this.aa=new qa(100,199)};var O=function(a){return(a=a.google_ad_modifications)?a.loeids||[]:[]},Yb=function(a,b,c){if(!a)return null;for(var d=0;d<a.length;++d)if((a[d].ad_slot||b)==b&&(a[d].ad_tag_origin||c)==c)return a[d];return null};var Zb=function(a,b,c){return A.location&&A.location.hash=="#google_plle_"+c?c:z([b,c],a)},$b=function(a,b,c,d){a=a.google_active_plles=a.google_active_plles||[];return J(O(b),c)?(a.push(c),c):J(O(b),d)?(a.push(d),d):null};var ac=null;var bc=function(a){this.s=a;a.google_iframe_oncopy||(a.google_iframe_oncopy={handlers:{},upd:t(this.ha,this)});this.ea=a.google_iframe_oncopy},cc;var P="var i=this.id,s=window.google_iframe_oncopy,H=s&&s.handlers,h=H&&H[i],w=this.contentWindow,d;try{d=w.document}catch(e){}if(h&&d&&(!d.body||!d.body.firstChild)){if(h.call){setTimeout(h,0)}else if(h.match){try{h=s.upd(h,i)}catch(e){}w.location.replace(h)}}";
/[\x00&<>"']/.test(P)&&(-1!=P.indexOf("&")&&(P=P.replace(ga,"&amp;")),-1!=P.indexOf("<")&&(P=P.replace(ia,"&lt;")),-1!=P.indexOf(">")&&(P=P.replace(ja,"&gt;")),-1!=P.indexOf('"')&&(P=P.replace(ka,"&quot;")),-1!=P.indexOf("'")&&(P=P.replace(la,"&#39;")),-1!=P.indexOf("\x00")&&(P=P.replace(ma,"&#0;")));cc=P;bc.prototype.set=function(a,b){this.ea.handlers[a]=b;this.s.addEventListener&&this.s.addEventListener("load",t(this.X,this,a),!1)};
bc.prototype.X=function(a){a=this.s.document.getElementById(a);try{var b=a.contentWindow.document;if(a.onload&&b&&(!b.body||!b.body.firstChild))a.onload()}catch(c){}};bc.prototype.ha=function(a,b){var c=dc("rx",a),d;a:{if(a&&(d=a.match("dt=([^&]+)"))&&2==d.length){d=d[1];break a}d=""}d=(new Date).getTime()-d;c=c.replace(/&dtd=(\d+|M)/,"&dtd="+(1E4>d?d+"":"M"));this.set(b,c);return c};var dc=function(a,b){var c=new RegExp("\\b"+a+"=(\\d+)"),d=c.exec(b);d&&(b=b.replace(c,a+"="+(+d[1]+1||1)));return b};var ec=!1,fc=function(a,b,c){var d=["<iframe"],e;for(e in a)a.hasOwnProperty(e)&&bb(d,e+"="+a[e]);e="left:0;position:absolute;top:0;";ec&&(e=e+"width:"+b+"px;height:"+c+"px;");d.push('style="'+e+'"');d.push("></iframe>");a=a.id;b="border:none;height:"+c+"px;margin:0;padding:0;position:relative;visibility:visible;width:"+b+"px;background-color:transparent";return['<ins id="',a+"_expand",'" style="display:inline-table;',b,'"><ins id="',a+"_anchor",'" style="display:block;',b,'">',d.join(" "),"</ins></ins>"].join("")};var gc=function(a){if(!a)return"";(a=a.toLowerCase())&&"ca-"!=a.substring(0,3)&&(a="ca-"+a);return a};var hc={"120x90":!0,"160x90":!0,"180x90":!0,"200x90":!0,"468x15":!0,"728x15":!0};var ic="google_ad_client google_ad_format google_ad_height google_ad_width google_city google_country google_encoding google_language google_page_url".split(" "),jc=function(a){try{var b=a.top.google_ads_params_store;if(b)return b;b=a.top.google_ads_params_store={};if(b===a.top.google_ads_params_store)return b}catch(c){}return null};var kc,S=function(a){this.B=[];this.s=a||window;this.o=0;this.A=null;this.S=0},lc=function(a,b){this.Y=a;this.ja=b};S.prototype.enqueue=function(a,b){0!=this.o||0!=this.B.length||b&&b!=window?this.K(a,b):(this.o=2,this.O(new lc(a,window)))};S.prototype.K=function(a,b){this.B.push(new lc(a,b||this.s));mc(this)};S.prototype.Z=function(a){this.o=1;if(a){var b=mb("sjr::timeout",t(this.N,this,!0));this.A=this.s.setTimeout(b,a)}};
S.prototype.N=function(a){a&&++this.S;1==this.o&&(null!=this.A&&(this.s.clearTimeout(this.A),this.A=null),this.o=0);mc(this)};S.prototype.da=function(){return!(!window||!Array)};S.prototype.fa=function(){return this.S};S.prototype.nq=S.prototype.enqueue;S.prototype.nqa=S.prototype.K;S.prototype.al=S.prototype.Z;S.prototype.rl=S.prototype.N;S.prototype.sz=S.prototype.da;S.prototype.tc=S.prototype.fa;var mc=function(a){var b=mb("sjr::tryrun",t(a.ga,a));a.s.setTimeout(b,0)};
S.prototype.ga=function(){if(0==this.o&&this.B.length){var a=this.B.shift();this.o=2;var b=mb("sjr::run",t(this.O,this,a));a.ja.setTimeout(b,0);mc(this)}};S.prototype.O=function(a){this.o=0;a.Y()};
var nc=function(a){try{return a.sz()}catch(b){return!1}},oc=function(a){return!!a&&("object"==typeof a||"function"==typeof a)&&nc(a)&&ab(a.nq)&&ab(a.nqa)&&ab(a.al)&&ab(a.rl)},pc=function(){if(kc&&nc(kc))return kc;var a=pb(),b=a.google_jobrunner;return oc(b)?kc=b:a.google_jobrunner=kc=new S(a)},qc=function(a,b){pc().nq(a,b)},rc=function(a,b){pc().nqa(a,b)};var T=function(a){this.name="TagError";this.message=a||"";Error.captureStackTrace?Error.captureStackTrace(this,T):this.stack=Error().stack||""};da(T,Error);
var sc=gb?1==eb(A):!eb(A),tc=function(){var a=Jb?"https":"http",b=u("script"),c;c=tb("","pagead2.googlesyndication.com");return["<",b,' src="',Wb(c,"/pagead/js/r20151014/r20151006/show_ads_impl.js",a),'"></',b,">"].join("")},uc=function(a,b,c,d){return function(){var e=!1;d&&pc().al(3E4);var g=a.document.getElementById(b);g&&!v(g.contentWindow)&&
3==a.google_top_js_status&&(a.google_top_js_status=6);try{var f=a.document.getElementById(b).contentWindow;if(v(f)){var h=a.document.getElementById(b).contentWindow,k=h.document;k.body&&k.body.firstChild||(k.open(),h.google_async_iframe_close=!0,k.write(c))}else{var l=a.document.getElementById(b).contentWindow,m;g=c;g=String(g);if(g.quote)m=g.quote();else{f=['"'];for(h=0;h<g.length;h++){var n=g.charAt(h),E=n.charCodeAt(0),k=f,V=h+1,F;if(!(F=na[n])){var y;if(31<E&&127>E)y=n;else{var q=n;if(q in oa)y=
oa[q];else if(q in na)y=oa[q]=na[q];else{var p=q,x=q.charCodeAt(0);if(31<x&&127>x)p=q;else{if(256>x){if(p="\\x",16>x||256<x)p+="0"}else p="\\u",4096>x&&(p+="0");p+=x.toString(16).toUpperCase()}y=oa[q]=p}}F=y}k[V]=F}f.push('"');m=f.join("")}l.location.replace("javascript:"+m)}e=!0}catch(I){l=pb().google_jobrunner,oc(l)&&l.rl()}e&&(e=dc("google_async_rrc",c),(new bc(a)).set(b,uc(a,b,e,!1)))}},vc=function(a){var b=["<iframe"];$a(a,function(a,d){null!=a&&b.push(" "+d+'="'+a+'"')});b.push("></iframe>");
return b.join("")},xc=function(a,b,c){wc(a,b,c,function(a,b,g){for(var f=a.document,h=b.id,k=0;!h||f.getElementById(h);)h="aswift_"+k++;b.id=h;b.name=h;var h=Number(g.google_ad_width),k=Number(g.google_ad_height),l=K.G;$b(g,a,l.j,l.i);ec=J(O(a),l.i);16==g.google_reactive_ad_format?(a=f.createElement("div"),a.innerHTML=fc(b,h,k),c.appendChild(a.firstChild)):c.innerHTML=fc(b,h,k);return b.id})},wc=function(a,b,c,d){var e=u("script"),g,f;a:{try{var h=a.top.google_pubvars_reuse_experiment;if("undefined"!==
typeof h){f=h;break a}h=z(["C","E"],Eb)||null;a.top.google_pubvars_reuse_experiment=h;if(a.top.google_pubvars_reuse_experiment===h){f=h;break a}}catch(ha){}f=null}if("E"===f){g=null!=b.google_ad_client;f=null!=b.google_ad_width;var h=null!=b.google_ad_height,k=jc(a);if(k){for(var l=0;l<ic.length;l++){var m=ic[l];null!=b[m]&&(k[m]=b[m])}if(k=jc(a)){var l=k.google_ad_width,m=k.google_ad_height,n=k.google_ad_format;l&&m&&n&&(n=(n=n&&n.match(/(\d+)x(\d+)/))?{width:n[1],height:n[2]}:null,!n||n.width==
l&&n.height==m||delete k.google_ad_format)}}if(k=jc(a))for(l=0;l<ic.length;l++)m=ic[l],null==b[m]&&null!=k[m]&&(b[m]=k[m]);k=null!=b.google_ad_client;l=null!=b.google_ad_width;m=null!=b.google_ad_height;g=[g?"c2":k?"c1":"c0",f?"w2":l?"w1":"w0",h?"h2":m?"h1":"h0"].join()}f={};h=b.google_ad_height;f.width='"'+b.google_ad_width+'"';f.height='"'+h+'"';f.frameborder='"0"';f.marginwidth='"0"';f.marginheight='"0"';f.vspace='"0"';f.hspace='"0"';f.allowtransparency='"true"';f.scrolling='"no"';f.allowfullscreen=
'"true"';f.onload='"'+cc+'"';d=d(a,f,b);h=b.google_ad_output;f=b.google_ad_format;f||"html"!=h&&null!=h||(f=b.google_ad_width+"x"+b.google_ad_height,b.google_ad_format_suffix&&(f+=b.google_ad_format_suffix));h=!b.google_ad_slot||b.google_override_format||!hc[b.google_ad_width+"x"+b.google_ad_height]&&"aa"==b.google_loader_used;f=f&&h?f.toLowerCase():"";b.google_ad_format=f;f=[b.google_ad_slot,b.google_ad_format,b.google_ad_type,b.google_ad_width,b.google_ad_height];h=[];k=0;for(l=c;l&&25>k;l=l.parentNode,
++k)h.push(9!=l.nodeType&&l.id||"");(h=h.join())&&f.push(h);b.google_ad_unit_key=fb(f.join(":")).toString();f=a.google_adk2_experiment=a.google_adk2_experiment||z(["C","E"],Bb)||"N";if("E"==f){f=[];for(h=0;c&&25>h;++h){k="";k=(k=9!=c.nodeType&&c.id)?"/"+k:"";a:{if(c&&c.nodeName&&c.parentElement)for(var l=c.nodeName.toString().toLowerCase(),m=c.parentElement.childNodes,E=n=0;E<m.length;++E){var V=m[E];if(V.nodeName&&V.nodeName.toString().toLowerCase()==l){if(c==V){l="."+n;break a}++n}}l=""}f.push((c.nodeName&&
c.nodeName.toString().toLowerCase())+k+l);c=c.parentElement}c=f.join()+":";f=a;h=[];if(f)try{for(var F=f.parent,k=0;F&&F!=f&&25>k;++k){for(var y=F.frames,l=0;l<y.length;++l)if(f==y[l]){h.push(l);break}f=F;F=f.parent}}catch(ha){}b.google_ad_unit_key_2=fb(c+h.join()).toString()}else"C"==f&&(b.google_ad_unit_key_2="ctrl");F=Tb(b);y=null;c=z(["C","E"],Fb);if("E"==c){a:{try{if(window.JSON&&window.JSON.stringify&&window.encodeURIComponent){var q=encodeURIComponent(window.JSON.stringify(b)),p;if(Rb)p=r.btoa(q);
else{f=[];for(k=h=0;k<q.length;k++){for(var x=q.charCodeAt(k);255<x;)f[h++]=x&255,x>>=8;f[h++]=x}if(!Qb)for(Qb={},q=0;65>q;q++)Qb[q]="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/=".charAt(q);q=Qb;x=[];for(h=0;h<f.length;h+=3){var I=f[h],Q=h+1<f.length,R=Q?f[h+1]:0,W=h+2<f.length,Db=W?f[h+2]:0,k=I>>2,l=(I&3)<<4|R>>4,m=(R&15)<<2|Db>>6,n=Db&63;W||(n=64,Q||(m=64));x.push(q[k],q[l],q[m],q[n])}p=x.join("")}y=p;break a}Da(ib,"sblob",{json:window.JSON?1:0,eURI:window.encodeURIComponent?
1:0},!0,void 0,void 0)}catch(ha){C.u("sblob",ha,void 0,void 0)}y=""}y||(y="{X}")}else"C"==c&&(y="{C}");var B;b=b.google_ad_client;if(p=sc){if(!ac)b:{I=[A.top];p=[];for(Q=0;R=I[Q++];){p.push(R);try{if(R.frames)for(var L=R.frames.length,W=0;W<L&&1024>I.length;++W)I.push(R.frames[W])}catch(ha){}}for(L=0;L<p.length;L++)try{if(B=p[L].frames.google_esf){ac=B;break b}}catch(ha){}ac=null}p=!ac}p?(B={style:"display:none"},B["data-ad-client"]=gc(b),B.id="google_esf",B.name="google_esf",B.src=Wb(tb("",
"googleads.g.doubleclick.net"),"/pagead/html/r20151014/r20151006/zrt_lookup.html"),B=vc(B)):B="";L=ea;b=(new Date).getTime();p=a.google_top_experiment;if(I=a.google_async_for_oa_experiment)a.google_async_for_oa_experiment=void 0;Q=a.google_always_use_delayed_impressions_experiment;B=["<!doctype html><html><body>",B,"<",e,">",F,"google_show_ads_impl=true;google_unique_id=",a.google_unique_id,';google_async_iframe_id="',d,'";google_start_time=',
L,";",c?'google_pub_vars = "'+y+'";':"",g?'google_pubvars_reuse_experiment_result = "'+g+'";':"",p?'google_top_experiment="'+p+'";':"",I?'google_async_for_oa_experiment="'+I+'";':"",Q?'google_always_use_delayed_impressions_experiment="'+Q+'";':"","google_bpp=",b>L?b-L:1,";google_async_rrc=0;</",e,">",tc(),"</body></html>"].join("");(a.document.getElementById(d)?qc:rc)(uc(a,d,B,!0))},yc=Math.floor(1E6*Math.random()),zc=function(a){var b;try{b={};for(var c=a.data.split("\n"),d=0;d<c.length;d++){var e=
c[d].indexOf("=");-1!=e&&(b[c[d].substr(0,e)]=c[d].substr(e+1))}}catch(g){}c=b[3];if(b[1]==yc&&(window.google_top_js_status=4,a.source==top&&0==c.indexOf(a.origin)&&(window.google_top_values=b,window.google_top_js_status=5),window.google_top_js_callbacks)){for(a=0;a<window.google_top_js_callbacks.length;a++)window.google_top_js_callbacks[a]();window.google_top_js_callbacks.length=0}},Ac=function(a,b){var c=navigator;if(Cb&&a&&b&&c){var d=a.document,c=d.createElement("script"),e=gc(b);c.async=!0;c.type=
"text/javascript";c.src=Wb("pagead2.googlesyndication.com","/pub-config/"+e+".js");d=d.getElementsByTagName("script")[0];d.parentNode.insertBefore(c,d)}};var U=function(a,b){this.M=a;this.L=b};U.prototype.minWidth=function(){return this.M};U.prototype.height=function(){return this.L};U.prototype.w=function(a){return 300<a&&300<this.L?this.M:1200<a?1200:Math.round(a)};var Bc={rectangle:1,horizontal:2,vertical:4,autorelaxed:1},X=function(a,b,c){U.call(this,a,b);this.ba=c};da(X,U);var Cc=function(a){return function(b){return!!(b.ba&a)}},Dc=[new X(970,90,2),new X(728,90,2),new X(468,60,2),new X(336,280,1),new X(320,100,2),new X(320,50,2),new X(300,600,4),new X(300,250,1),new X(250,250,1),new X(234,60,2),new X(200,200,1),new X(180,150,1),new X(160,600,4),new X(125,125,1),new X(120,600,4),new X(120,240,4)];var Ec=function(a,b){for(var c=["width","height"],d=0;d<c.length;d++){var e="google_ad_"+c[d];if(!b.hasOwnProperty(e)){var g;g=za(a[c[d]]);g=null===g?null:Math.round(g);null!=g&&(b[e]=g)}}},Fc=function(a,b){try{var c=b.document.documentElement.getBoundingClientRect(),d=a.getBoundingClientRect();return{x:d.left-c.left,y:d.top-c.top}}catch(e){return null}},Gc=function(a){var b=0,c;for(c in Bc)-1!=a.indexOf(c)&&(b|=Bc[c]);return b};var Hc=function(a){return function(b){return b.minWidth()<=a}},Jc=function(a,b,c){var d=a&&Ic(c,b);return function(a){return!(d&&250<=a.height())}},Ic=function(a,b){var c=Math.min(N(b).clientHeight,16*N(b).clientWidth/9),d=Fc(a,b);return(d?d.y:0)<c-100},Lc=function(a,b){var c=b,d=Infinity;do{var e=Kc(c,a,"height");e&&(d=Math.min(d,e));(e=Kc(c,a,"maxHeight"))&&(d=Math.min(d,e))}while((c=c.parentElement)&&"HTML"!=c.tagName);return d},Kc=function(a,b,c){if(a.style){var d=za(a.style[c]);if(d)return d}if(a=
w(a,b))if(d=za(a[c]))return d;return null};var Mc=function(a){return function(b){for(var c=a.length-1;0<=c;--c)if(!a[c](b))return!1;return!0}},Nc=function(a,b,c){for(var d=a.length,e=null,g=0;g<d;++g){var f=a[g];if(b(f)){if(!c||c(f))return f;null===e&&(e=f)}}return e};var Pc=function(a,b,c,d){var e=Dc.slice(0);if(J(O(c),K.F.i))for(var g=Math.random,f=e.length-1;0<f;f--){var h=Math.floor(g()*(f+1)),k=e[f];e[f]=e[h];e[h]=k}g=488>N(c).clientWidth;b=[Hc(a),Oc(g),Jc(g,c,d),Cc(b)];e=Nc(e,Mc(b));if(!e)throw new T("adsbygoogle.push() error: No slot size for availableWidth="+a);return e},Oc=function(a){return function(b){return!(320==b.minWidth()&&(a&&50==b.height()||!a&&100==b.height()))}};var Y=function(a,b){U.call(this,a,b)};da(Y,U);Y.prototype.w=function(a){return Math.min(1200,Math.round(a))};var Qc=[new Y(301,300),new Y(120,600)],Rc=[new Y(468,300),new Y(414,828),new Y(384,768),new Y(375,750),new Y(360,720),new Y(320,640),new Y(120,600)],Sc=function(a,b){var c=Nc(a,Hc(b));if(!c)throw new T("adsbygoogle.push() error: No autorelaxed size for width="+b+"px");return c};var Tc=function(){return G("iPad")||G("Android")&&!G("Mobile")||G("Silk")};var Uc=[{l:[3,0,0],m:[6,12,14,0,1,3,2,4,13,5,7,8,9,10,11,15]},{l:[3,0,1],m:[6,15,0,1,2,3,4,13,5,7,8,9,10,11,12,14]},{l:[3,0,2],m:[6,15,0,1,2,3,4,7,8,9,10,13,5,11,12,14]},{l:[3,1,0],m:[6,12,15,0,1,3,4,13,2,5,7,8,9,10,11,14]},{l:[3,1,1],m:[6,15,0,1,7,8,11,2,3,4,5,9,10,12,13,14]},{l:[3,1,2],m:[6,15,0,1,2,3,4,7,9,11,5,8,10,12,13,14]},{l:[3,2,0],m:[0,6,12,15,1,2,3,4,13,5,7,8,9,10,11,14]},{l:[3,2,1],m:[0,6,12,14,1,2,3,4,13,5,7,8,9,10,11,15]},{l:[3,2,2],m:[0,15,1,2,3,4,13,9,5,6,7,8,10,11,12,14]},{l:[2,0,
0],m:[6,15,0,1,3,2,7,8,10,13,9,4,5,11,12,14]},{l:[2,0,1],m:[6,15,0,1,2,3,7,8,4,10,9,13,5,11,12,14]},{l:[2,0,2],m:[0,15,1,2,3,4,7,8,13,5,6,9,10,11,12,14]},{l:[4,0,0],m:[6,12,14,15,0,1,7,2,8,11,9,3,4,5,10,13]},{l:[4,0,1],m:[6,12,14,0,1,2,3,4,7,8,11,13,5,9,10,15]},{l:[4,0,2],m:[6,15,0,1,2,3,5,7,8,13,9,4,10,11,12,14]}],Vc=function(a,b,c){return"auto"==c?(b/=Math.min(1200,N(a).clientWidth),.6<b&&!(488>N(a).clientWidth)?2:.25>=b?4:3):Gc(c)},Wc=function(a,b){var c=Lc(a,b);return function(a){return a.height()<=
c}},Yc=function(a,b,c,d,e){var g;a:{var f;f=!Tc()&&(G("iPod")||G("iPhone")||G("Android")||G("IEMobile"))?2:Tc()?4:3;g=Fc(d,c);f=[f,g&&3==f?83>g.x?0:265>g.x?1:2:0,Xc(f,g)];for(g=0;g<Uc.length;++g){var h=Uc[g],k;b:if(k=h.l,f&&"number"==typeof f.length&&k&&"number"==typeof k.length&&f.length==k.length){for(var l=f.length,m=0;m<l;m++)if(f[m]!==k[m]){k=!1;break b}k=!0}else k=!1;if(k){g=h.m;break a}}throw Error("No format for "+f);}f=[];for(h=0;h<g.length;++h)f.push(Dc[g[h]]);g=488>N(c).clientWidth;a=[Wc(c,
d),Hc(a),Jc(g,c,d)];c=[];(e?c:a).push(Cc(b));return Nc(f,Mc(a),Mc(c))},Xc=function(a,b){if(!b)return 0;var c=b.y;switch(a){case 2:return 285>c?0:1396>c?1:2;case 4:return 275>c?0:1057>c?1:2;default:return 216>c?0:838>c?1:2}};var Z=function(a,b){U.call(this,a,b)};da(Z,U);Z.prototype.w=function(){return this.minWidth()};var Zc=[new Z(728,15),new Z(468,15),new Z(200,90),new Z(180,90),new Z(160,90),new Z(120,90)];var $c=function(a){return hb.test(a.className)&&"done"!=a.getAttribute("data-adsbygoogle-status")},bd=function(a,b){var c=window;a.setAttribute("data-adsbygoogle-status","done");ad(a,b,c)},ad=function(a,b,c){cd(a,b,c);if(!dd(a,b,c)){if(b.google_reactive_ads_config){if(ed)throw new T("adsbygoogle.push() error: Only one 'enable_page_level_ads' allowed per page.");ed=!0}db(c);1==eb(c)&&Ac(c,b.google_ad_client);$a(Sb,function(a,d){b[d]=b[d]||c[d]});b.google_loader_used="aa";var d=b.google_ad_output;if(d&&
"html"!=d)throw new T("adsbygoogle.push() error: No support for google_ad_output="+d);kb("aa::load",lb,function(){xc(c,b,a)})}},dd=function(a,b,c){var d=b.google_reactive_ads_config;if(d)var e=d.page_level_pubvars,g=(aa(e)?e:{}).google_tag_origin;var f=b.google_ad_slot,e=c.google_ad_modifications;!e||Yb(e.ad_whitelist,f,g||b.google_tag_origin)?e=null:(g=e.space_collapsing||"none",e=(f=Yb(e.ad_blacklist,f))?{I:!0,R:f.space_collapsing||g}:e.remove_ads_by_default?{I:!0,R:g}:null);return e&&e.I&&"on"!=
b.google_adtest?("slot"==e.R&&(null!==ya(a.getAttribute("width"))&&a.setAttribute("width",0),null!==ya(a.getAttribute("height"))&&a.setAttribute("height",0),a.style.width="0px",a.style.height="0px"),!0):!(e=w(a,c))||"none"!=e.display||"on"==b.google_adtest||0<b.google_reactive_ad_format||d?!1:(c.document.createComment&&a.appendChild(c.document.createComment("No ad requested because of display:none on the adsbygoogle tag")),!0)},fd=function(a,b){var c;try{c=a.getBoundingClientRect()}catch(e){}if(!c||
0==c.left&&0==c.right&&0==c.width&&0==c.height)return!1;var d=w(a,b);if(!d)return!1;c=za(d.width);d=za(d.height);return null==c||null==d||hc[c+"x"+d]?!1:!0},cd=function(a,b,c){for(var d=a.attributes,e=d.length,g=0;g<e;g++){var f=d[g];if(/data-/.test(f.name)){var h=f.name.replace("data","google").replace(/-/g,"_");if(!b.hasOwnProperty(h)){var f=f.value,k={google_reactive_ad_format:qb,google_allow_expandable_ads:rb},f=k.hasOwnProperty(h)?k[h](f,null):f;null===f||(b[h]=f)}}}if(b.google_enable_content_recommendations&&
1==b.google_reactive_ad_format)b.google_ad_width=N(c).clientWidth,b.google_ad_height=50,a.style.display="none";else if(1==b.google_reactive_ad_format)b.google_ad_width=320,b.google_ad_height=50,a.style.display="none";else if(8==b.google_reactive_ad_format)b.google_ad_width=N(c).clientWidth||0,b.google_ad_height=N(c).clientHeight||0,a.style.display="none";else if(9==b.google_reactive_ad_format)b.google_ad_width=N(c).clientWidth||0,b.google_ad_height=N(c).clientHeight||0,a.style.display="none";else{d=
b.google_ad_format;"autorelaxed"==d?(d=K.C,$b(b,c,d.j,d.i),d=J(O(c),K.C.i)?3:2):"auto"==d||/^((^|,) *(horizontal|vertical|rectangle) *)+$/.test(d)?(d=K.D,$b(b,c,d.j,d.i),d=J(O(c),K.D.i)||J(O(c),K.v.i)?5:1):d="link"==d?4:void 0;if(e=!d)fd(a,c)?(e=K.v,$b(b,c,e.j,e.i)!==e.i?e=!1:(b.google_ad_format="auto",e=!0)):e=!1;e&&(d=5);if(d){var l=a.offsetWidth;a:{var m=b.google_ad_format;switch(d){default:case 1:var n="auto"==m?.25>=l/Math.min(1200,N(c).clientWidth)?4:3:Gc(m);b&&(b.google_responsive_formats=
n,m=K.F,$b(b,c,m.j,m.i));c=Pc(l,n,c,a);break a;case 2:c=Sc(Qc,l);break a;case 3:c=Sc(Rc,l);break a;case 5:m=Vc(c,l,m);b.google_responsive_formats=m;var E=J(O(c),K.v.i);b:{d=a;do if((e=w(d,c))&&"fixed"==e.position){d=!1;break b}while(d=d.parentElement);d=!0}d&&(n=Yc(l,m,c,a,E));c=n||Pc(l,m,c,a);break a;case 4:c=Nc(Zc,Hc(l));if(!c)throw new T("adsbygoogle.push() error: No link unit size for width="+l+"px");b.google_ad_format_suffix="_0ads_al";b.google_override_format=1}}b.google_ad_width=c.w(l);b.google_ad_height=
c.height();a.style.height=c.height()+"px";b.google_ad_resizable=!0;delete b.google_ad_format;b.google_loader_features_used=128}else{n=fd(a,c)?(n=z(["LC","LE"],Ab))?"LE"==(b.google_responsive_override_logs_experiment=n):!1:!1;if(n)try{m=a.offsetWidth,E=Yc(m,Vc(c,m,"auto"),c,a,!0),l=new ra(E.w(m),E.height()),b.google_ember_w=l.width,b.google_ember_h=l.height}catch(V){b.google_ember_w=b.google_ember_h="e"}!xa.test(b.google_ad_width)&&!wa.test(a.style.width)||!xa.test(b.google_ad_height)&&!wa.test(a.style.height)?
(c=w(a,c),a.style.width=c.width,a.style.height=c.height,Ec(c,b),b.google_ad_width||(b.google_ad_width=a.offsetWidth),b.google_ad_height||(b.google_ad_height=a.offsetHeight),b.google_loader_features_used=256):(Ec(a.style,b),b.google_ad_output&&"html"!=b.google_ad_output||300!=b.google_ad_width||250!=b.google_ad_height||(c=a.style.width,a.style.width="100%",n=a.offsetWidth,a.style.width=c,b.google_available_width=n))}}},gd=function(a){for(var b=document.getElementsByTagName("ins"),c=0,d=b[c];c<b.length;d=
b[++c])if($c(d)&&(!a||d.id==a))return d;return null},ed=!1,hd=function(a,b){var c={};$a(Ub,function(b,d){a.hasOwnProperty(d)&&(c[d]=a[d])});aa(a.enable_page_level_ads)&&(c.page_level_pubvars=a.enable_page_level_ads);var d=document.createElement("ins");d.className="adsbygoogle";d.style.display="none";b?Za.body.appendChild(d):Za.documentElement.appendChild(d);bd(d,{google_reactive_ads_config:c,google_ad_client:a.google_ad_client})},id=function(a){if(!ta())throw new T("adsbygoogle.push() error: Page-level tag does not work inside iframes.");
var b=J(O(A),K.H.i),c=!b;Za.body||b?hd(a,c):cb(nb(function(){hd(a,c)}))},jd=function(a,b,c,d){if(0==b.message.indexOf("TagError")){var e={};Ja(C,e,d);e.context=a;e.msg=b.message.substring(0,512);a=r.document;e.url=a.URL.substring(0,512);e.ref=a.referrer.substring(0,512);Da(ib,"puberror",e,!0,c||.01);return!1}return C.u(a,b,c,d)},kd=function(a,b,c,d){return 0==b.message.indexOf("TagError")?!1:C.u(a,b,c,d)},md=function(a){var b={};kb("aa::hqe",jd,function(){ld(a,b)},function(c){c.client=c.client||b.google_ad_client||
a.google_ad_client;c.slotname=c.slotname||b.google_ad_slot;c.tag_origin=c.tag_origin||b.google_tag_origin})},ld=function(a,b){ea=(new Date).getTime();var c;a:{if(a.enable_page_level_ads){if("string"==typeof a.google_ad_client){c=!0;break a}throw new T("adsbygoogle.push() error: 'google_ad_client' is missing from the tag config.");}c=!1}if(c)id(a);else{c=a.element;var d=a.params;d&&$a(d,function(a,c){b[c]=a});if(c){if(!$c(c)&&(c=c.id?gd(c.id):null,!c))throw new T("adsbygoogle.push() error: 'element' has already been filled.");
if(!("innerHTML"in c))throw new T("adsbygoogle.push() error: 'element' is not a good DOM element.");}else if(c=gd(),!c)throw new T("adsbygoogle.push() error: All ins elements in the DOM with class=adsbygoogle already have ads in them.");bd(c,b)}},od=function(){kb("aa::main",kd,nd)},nd=function(){var a=A.google_ad_modifications=A.google_ad_modifications||{};if(!a.plle){a.plle=!0;a=a.loeids=a.loeids||[];fa("")&&a.push("");var b=K.D,
c=b.i;if(A.location&&A.location.hash=="#google_plle_"+c)b=c;else{var b=[b.j,c],c=new qa(vb,vb+wb-1),d;(d=0>=wb||wb%b.length)||(d=Xb.aa,d=!(d.start<=c.start&&d.end>=c.end));d?b=null:(d=Aa(),b=null!==d&&c.start<=d&&c.end>=d?b[(d-vb)%b.length]:null)}b&&a.push(b);b=K.C;(b=Zb(xb,b.j,b.i))&&a.push(b);b=K.F;(b=Zb(yb,b.j,b.i))&&a.push(b);b=K.v;(b=Zb(zb,b.j,b.i))&&a.push(b);b=K.G;(b=Zb(Gb,b.j,b.i))&&a.push(b);Za.body||(b=K.H,(b=Zb(Hb,b.j,b.i))&&a.push(b))}if(!window.google_top_experiment&&!window.google_top_js_status)if(a=
window,2!==(a.top==a?0:v(a.top)?1:2))window.google_top_js_status=0;else if(top.postMessage){var e;try{e=A.top.frames.google_top_static_frame?!0:!1}catch(f){e=!1}if(e){if(window.google_top_experiment=z(["jp_c","jp_zl","jp_wfpmr","jp_zlt","jp_wnt"],ub),"jp_c"!==window.google_top_experiment){sa(window,"message",zc);window.google_top_js_status=3;e={0:"google_loc_request",1:yc};var a=[],g;for(g in e)a.push(g+"="+e[g]);top.postMessage(a.join("\n"),"*")}}else window.google_top_js_status=2}else window.google_top_js_status=
1;if((g=window.adsbygoogle)&&g.shift)for(a=20;(e=g.shift())&&0<a--;)try{md(e)}catch(f){throw window.setTimeout(od,0),f;}if(!g||!g.loaded){window.adsbygoogle={push:md,loaded:!0};g&&pd(g.onload);try{Object.defineProperty(window.adsbygoogle,"onload",{set:pd})}catch(f){}}},pd=function(a){ab(a)&&window.setTimeout(a,0)};od();}).call(this);