(function (cjs, an) {

var p; // shortcut to reference prototypes
var lib={};var ss={};var img={};
lib.ssMetadata = [];


(lib.AnMovieClip = function(){
	this.actionFrames = [];
	this.ignorePause = false;
	this.gotoAndPlay = function(positionOrLabel){
		cjs.MovieClip.prototype.gotoAndPlay.call(this,positionOrLabel);
	}
	this.play = function(){
		cjs.MovieClip.prototype.play.call(this);
	}
	this.gotoAndStop = function(positionOrLabel){
		cjs.MovieClip.prototype.gotoAndStop.call(this,positionOrLabel);
	}
	this.stop = function(){
		cjs.MovieClip.prototype.stop.call(this);
	}
}).prototype = p = new cjs.MovieClip();
// symbols:



(lib.arrow = function() {
	this.initialize(img.arrow);
}).prototype = p = new cjs.Bitmap();
p.nominalBounds = new cjs.Rectangle(0,0,600,500);


(lib.bg = function() {
	this.initialize(img.bg);
}).prototype = p = new cjs.Bitmap();
p.nominalBounds = new cjs.Rectangle(0,0,600,500);


(lib.copy1A = function() {
	this.initialize(img.copy1A);
}).prototype = p = new cjs.Bitmap();
p.nominalBounds = new cjs.Rectangle(0,0,600,500);


(lib.copy2 = function() {
	this.initialize(img.copy2);
}).prototype = p = new cjs.Bitmap();
p.nominalBounds = new cjs.Rectangle(0,0,600,500);


(lib.cta = function() {
	this.initialize(img.cta);
}).prototype = p = new cjs.Bitmap();
p.nominalBounds = new cjs.Rectangle(0,0,600,500);// helper functions:

function mc_symbol_clone() {
	var clone = this._cloneProps(new this.constructor(this.mode, this.startPosition, this.loop, this.reversed));
	clone.gotoAndStop(this.currentFrame);
	clone.paused = this.paused;
	clone.framerate = this.framerate;
	return clone;
}

function getMCSymbolPrototype(symbol, nominalBounds, frameBounds) {
	var prototype = cjs.extend(symbol, cjs.MovieClip);
	prototype.clone = mc_symbol_clone;
	prototype.nominalBounds = nominalBounds;
	prototype.frameBounds = frameBounds;
	return prototype;
	}


(lib.hit = function(mode,startPosition,loop,reversed) {
if (loop == null) { loop = true; }
if (reversed == null) { reversed = false; }
	var props = new Object();
	props.mode = mode;
	props.startPosition = startPosition;
	props.labels = {};
	props.loop = loop;
	props.reversed = reversed;
	cjs.MovieClip.apply(this,[props]);

	// Layer_1
	this.shape = new cjs.Shape();
	this.shape.graphics.f("#FFFFFF").s().p("A3bTiMAAAgnDMAu3AAAMAAAAnDg");
	this.shape.setTransform(150,125);

	this.timeline.addTween(cjs.Tween.get(this.shape).wait(1));

	this._renderFirstFrame();

}).prototype = getMCSymbolPrototype(lib.hit, new cjs.Rectangle(0,0,300,250), null);


(lib.highlight_shape = function(mode,startPosition,loop,reversed) {
if (loop == null) { loop = true; }
if (reversed == null) { reversed = false; }
	var props = new Object();
	props.mode = mode;
	props.startPosition = startPosition;
	props.labels = {};
	props.loop = loop;
	props.reversed = reversed;
	cjs.MovieClip.apply(this,[props]);

	// Layer_1
	this.shape = new cjs.Shape();
	this.shape.graphics.f("#0B385E").s().p("A6ZBVIAAipMA0zAAAIAACpg");
	this.shape.setTransform(169,8.7501,1,1.0294);

	this.timeline.addTween(cjs.Tween.get(this.shape).wait(1));

	this._renderFirstFrame();

}).prototype = getMCSymbolPrototype(lib.highlight_shape, new cjs.Rectangle(0,0,338,17.5), null);


(lib.cta_copy = function(mode,startPosition,loop,reversed) {
if (loop == null) { loop = true; }
if (reversed == null) { reversed = false; }
	var props = new Object();
	props.mode = mode;
	props.startPosition = startPosition;
	props.labels = {};
	props.loop = loop;
	props.reversed = reversed;
	cjs.MovieClip.apply(this,[props]);

	// Layer_1
	this.instance = new lib.cta();
	this.instance.setTransform(0,0,0.5,0.5);

	this.timeline.addTween(cjs.Tween.get(this.instance).wait(1));

	this._renderFirstFrame();

}).prototype = getMCSymbolPrototype(lib.cta_copy, new cjs.Rectangle(0,0,300,250), null);


(lib.cta_bg = function(mode,startPosition,loop,reversed) {
if (loop == null) { loop = true; }
if (reversed == null) { reversed = false; }
	var props = new Object();
	props.mode = mode;
	props.startPosition = startPosition;
	props.labels = {};
	props.loop = loop;
	props.reversed = reversed;
	cjs.MovieClip.apply(this,[props]);

	// Layer_1
	this.shape = new cjs.Shape();
	this.shape.graphics.f("#0B385E").s().p("ArUBzIAAjlIWpAAIAADlg");
	this.shape.setTransform(72.5,11.5);

	this.timeline.addTween(cjs.Tween.get(this.shape).wait(1));

	this._renderFirstFrame();

}).prototype = getMCSymbolPrototype(lib.cta_bg, new cjs.Rectangle(0,0,145,23), null);


(lib.copy2_1 = function(mode,startPosition,loop,reversed) {
if (loop == null) { loop = true; }
if (reversed == null) { reversed = false; }
	var props = new Object();
	props.mode = mode;
	props.startPosition = startPosition;
	props.labels = {};
	props.loop = loop;
	props.reversed = reversed;
	cjs.MovieClip.apply(this,[props]);

	// Layer_1
	this.instance = new lib.copy2();
	this.instance.setTransform(0,0,0.5,0.5);

	this.timeline.addTween(cjs.Tween.get(this.instance).wait(1));

	this._renderFirstFrame();

}).prototype = getMCSymbolPrototype(lib.copy2_1, new cjs.Rectangle(0,0,300,250), null);


(lib.copy1A_1 = function(mode,startPosition,loop,reversed) {
if (loop == null) { loop = true; }
if (reversed == null) { reversed = false; }
	var props = new Object();
	props.mode = mode;
	props.startPosition = startPosition;
	props.labels = {};
	props.loop = loop;
	props.reversed = reversed;
	cjs.MovieClip.apply(this,[props]);

	// Layer_1
	this.instance = new lib.copy1A();
	this.instance.setTransform(0,0,0.5,0.5);

	this.timeline.addTween(cjs.Tween.get(this.instance).wait(1));

	this._renderFirstFrame();

}).prototype = getMCSymbolPrototype(lib.copy1A_1, new cjs.Rectangle(0,0,300,250), null);


(lib.arrow_1 = function(mode,startPosition,loop,reversed) {
if (loop == null) { loop = true; }
if (reversed == null) { reversed = false; }
	var props = new Object();
	props.mode = mode;
	props.startPosition = startPosition;
	props.labels = {};
	props.loop = loop;
	props.reversed = reversed;
	cjs.MovieClip.apply(this,[props]);

	// Layer_1
	this.instance = new lib.arrow();
	this.instance.setTransform(0,0,0.5,0.5);

	this.timeline.addTween(cjs.Tween.get(this.instance).wait(1));

	this._renderFirstFrame();

}).prototype = getMCSymbolPrototype(lib.arrow_1, new cjs.Rectangle(0,0,300,250), null);


(lib.highlight = function(mode,startPosition,loop,reversed) {
if (loop == null) { loop = true; }
if (reversed == null) { reversed = false; }
	var props = new Object();
	props.mode = mode;
	props.startPosition = startPosition;
	props.labels = {};
	props.loop = loop;
	props.reversed = reversed;
	cjs.MovieClip.apply(this,[props]);

	// Layer_1
	this.h1 = new lib.highlight_shape();
	this.h1.name = "h1";
	this.h1.setTransform(142.55,103,0.2397,1,0,0,0,0.2,0);

	this.h2 = new lib.highlight_shape();
	this.h2.name = "h2";
	this.h2.setTransform(14.05,131.35,0.5997,1,0,0,0,0.1,0.1);

	this.timeline.addTween(cjs.Tween.get({}).to({state:[{t:this.h2},{t:this.h1}]}).wait(1));

	this._renderFirstFrame();

}).prototype = getMCSymbolPrototype(lib.highlight, new cjs.Rectangle(14,103,209.6,45.80000000000001), null);


(lib.cta_1 = function(mode,startPosition,loop,reversed) {
if (loop == null) { loop = true; }
if (reversed == null) { reversed = false; }
	var props = new Object();
	props.mode = mode;
	props.startPosition = startPosition;
	props.labels = {};
	props.loop = loop;
	props.reversed = reversed;
	cjs.MovieClip.apply(this,[props]);

	// timeline functions:
	this.frame_0 = function() {
		this.stop();
	}
	this.frame_59 = function() {
		this.stop();
	}

	// actions tween:
	this.timeline.addTween(cjs.Tween.get(this).call(this.frame_0).wait(59).call(this.frame_59).wait(1));

	// Layer_3 (mask)
	var mask = new cjs.Shape();
	mask._off = true;
	var mask_graphics_0 = new cjs.Graphics().p("ArUQGIAAjmIWpAAIAADmg");
	var mask_graphics_1 = new cjs.Graphics().p("ArUQGIAAjmIWpAAIAADmg");
	var mask_graphics_2 = new cjs.Graphics().p("ArUQGIAAjmIWpAAIAADmg");
	var mask_graphics_3 = new cjs.Graphics().p("ArUQGIAAjmIWpAAIAADmg");
	var mask_graphics_4 = new cjs.Graphics().p("ArUQGIAAjmIWpAAIAADmg");
	var mask_graphics_5 = new cjs.Graphics().p("ArUQGIAAjmIWpAAIAADmg");
	var mask_graphics_6 = new cjs.Graphics().p("ArUQGIAAjmIWpAAIAADmg");
	var mask_graphics_7 = new cjs.Graphics().p("ArUQGIAAjmIWpAAIAADmg");
	var mask_graphics_8 = new cjs.Graphics().p("ArUQGIAAjmIWpAAIAADmg");
	var mask_graphics_9 = new cjs.Graphics().p("ArUQGIAAjmIWpAAIAADmg");
	var mask_graphics_10 = new cjs.Graphics().p("ArUQGIAAjmIWpAAIAADmg");
	var mask_graphics_11 = new cjs.Graphics().p("ArUQGIAAjmIWpAAIAADmg");
	var mask_graphics_12 = new cjs.Graphics().p("ArUQGIAAjmIWpAAIAADmg");
	var mask_graphics_13 = new cjs.Graphics().p("ArUQGIAAjmIWpAAIAADmg");
	var mask_graphics_14 = new cjs.Graphics().p("ArUQGIAAjmIWpAAIAADmg");
	var mask_graphics_15 = new cjs.Graphics().p("ArUQGIAAjmIWpAAIAADmg");
	var mask_graphics_16 = new cjs.Graphics().p("ArUQGIAAjmIWpAAIAADmg");
	var mask_graphics_17 = new cjs.Graphics().p("ArUQGIAAjmIWpAAIAADmg");
	var mask_graphics_18 = new cjs.Graphics().p("ArUQGIAAjmIWpAAIAADmg");
	var mask_graphics_19 = new cjs.Graphics().p("ArUQGIAAjmIWpAAIAADmg");
	var mask_graphics_20 = new cjs.Graphics().p("ArUQGIAAjmIWpAAIAADmg");
	var mask_graphics_21 = new cjs.Graphics().p("ArUQGIAAjmIWpAAIAADmg");
	var mask_graphics_22 = new cjs.Graphics().p("ArUQGIAAjmIWpAAIAADmg");
	var mask_graphics_23 = new cjs.Graphics().p("ArUQGIAAjmIWpAAIAADmg");
	var mask_graphics_24 = new cjs.Graphics().p("ArUQGIAAjmIWpAAIAADmg");
	var mask_graphics_25 = new cjs.Graphics().p("ArUQGIAAjmIWpAAIAADmg");
	var mask_graphics_26 = new cjs.Graphics().p("ArUQGIAAjmIWpAAIAADmg");
	var mask_graphics_27 = new cjs.Graphics().p("ArUQGIAAjmIWpAAIAADmg");
	var mask_graphics_28 = new cjs.Graphics().p("ArUQGIAAjmIWpAAIAADmg");
	var mask_graphics_29 = new cjs.Graphics().p("ArUQGIAAjmIWpAAIAADmg");
	var mask_graphics_30 = new cjs.Graphics().p("ArUQGIAAjmIWpAAIAADmg");
	var mask_graphics_31 = new cjs.Graphics().p("ArUQGIAAjmIWpAAIAADmg");
	var mask_graphics_32 = new cjs.Graphics().p("ArUQGIAAjmIWpAAIAADmg");
	var mask_graphics_33 = new cjs.Graphics().p("ArUQGIAAjmIWpAAIAADmg");
	var mask_graphics_34 = new cjs.Graphics().p("ArUQGIAAjmIWpAAIAADmg");
	var mask_graphics_35 = new cjs.Graphics().p("ArUQGIAAjmIWpAAIAADmg");
	var mask_graphics_36 = new cjs.Graphics().p("ArUQGIAAjmIWpAAIAADmg");
	var mask_graphics_37 = new cjs.Graphics().p("ArUQGIAAjmIWpAAIAADmg");
	var mask_graphics_38 = new cjs.Graphics().p("ArUQGIAAjmIWpAAIAADmg");
	var mask_graphics_39 = new cjs.Graphics().p("ArUQGIAAjmIWpAAIAADmg");
	var mask_graphics_40 = new cjs.Graphics().p("ArUQGIAAjmIWpAAIAADmg");
	var mask_graphics_41 = new cjs.Graphics().p("ArNQGIAAjmIWpAAIAADmg");
	var mask_graphics_42 = new cjs.Graphics().p("ArCQGIAAjmIWpAAIAADmg");
	var mask_graphics_43 = new cjs.Graphics().p("Aq6QGIAAjmIWpAAIAADmg");
	var mask_graphics_44 = new cjs.Graphics().p("AqzQGIAAjmIWpAAIAADmg");
	var mask_graphics_45 = new cjs.Graphics().p("AqtQGIAAjmIWpAAIAADmg");
	var mask_graphics_46 = new cjs.Graphics().p("AqoQGIAAjmIWpAAIAADmg");
	var mask_graphics_47 = new cjs.Graphics().p("AqkQGIAAjmIWpAAIAADmg");
	var mask_graphics_48 = new cjs.Graphics().p("AqiQGIAAjmIWpAAIAADmg");
	var mask_graphics_49 = new cjs.Graphics().p("AqfQGIAAjmIWpAAIAADmg");
	var mask_graphics_50 = new cjs.Graphics().p("AqeQGIAAjmIWpAAIAADmg");
	var mask_graphics_51 = new cjs.Graphics().p("AqcQGIAAjmIWpAAIAADmg");
	var mask_graphics_52 = new cjs.Graphics().p("AqcQGIAAjmIWpAAIAADmg");
	var mask_graphics_53 = new cjs.Graphics().p("AqbQGIAAjmIWpAAIAADmg");
	var mask_graphics_54 = new cjs.Graphics().p("AqbQGIAAjmIWpAAIAADmg");
	var mask_graphics_55 = new cjs.Graphics().p("AqbQGIAAjmIWpAAIAADmg");
	var mask_graphics_56 = new cjs.Graphics().p("AqbQGIAAjmIWpAAIAADmg");
	var mask_graphics_57 = new cjs.Graphics().p("AqbQGIAAjmIWpAAIAADmg");
	var mask_graphics_58 = new cjs.Graphics().p("AqaQGIAAjmIWpAAIAADmg");
	var mask_graphics_59 = new cjs.Graphics().p("AqaQGIAAjmIWpAAIAADmg");

	this.timeline.addTween(cjs.Tween.get(mask).to({graphics:mask_graphics_0,x:-61,y:103}).wait(1).to({graphics:mask_graphics_1,x:-60.9999,y:103}).wait(1).to({graphics:mask_graphics_2,x:-60.9985,y:103}).wait(1).to({graphics:mask_graphics_3,x:-60.9922,y:103}).wait(1).to({graphics:mask_graphics_4,x:-60.9755,y:103}).wait(1).to({graphics:mask_graphics_5,x:-60.9402,y:103}).wait(1).to({graphics:mask_graphics_6,x:-60.8759,y:103}).wait(1).to({graphics:mask_graphics_7,x:-60.7702,y:103}).wait(1).to({graphics:mask_graphics_8,x:-60.6079,y:103}).wait(1).to({graphics:mask_graphics_9,x:-60.3719,y:103}).wait(1).to({graphics:mask_graphics_10,x:-60.0427,y:103}).wait(1).to({graphics:mask_graphics_11,x:-59.5984,y:103}).wait(1).to({graphics:mask_graphics_12,x:-59.0149,y:103}).wait(1).to({graphics:mask_graphics_13,x:-58.2658,y:103}).wait(1).to({graphics:mask_graphics_14,x:-57.3224,y:103}).wait(1).to({graphics:mask_graphics_15,x:-56.1536,y:103}).wait(1).to({graphics:mask_graphics_16,x:-54.7262,y:103}).wait(1).to({graphics:mask_graphics_17,x:-53.0045,y:103}).wait(1).to({graphics:mask_graphics_18,x:-50.9506,y:103}).wait(1).to({graphics:mask_graphics_19,x:-48.5243,y:103}).wait(1).to({graphics:mask_graphics_20,x:-45.6831,y:103}).wait(1).to({graphics:mask_graphics_21,x:-42.3823,y:103}).wait(1).to({graphics:mask_graphics_22,x:-38.5746,y:103}).wait(1).to({graphics:mask_graphics_23,x:-34.2107,y:103}).wait(1).to({graphics:mask_graphics_24,x:-29.2389,y:103}).wait(1).to({graphics:mask_graphics_25,x:-23.6053,y:103}).wait(1).to({graphics:mask_graphics_26,x:-17.2535,y:103}).wait(1).to({graphics:mask_graphics_27,x:-10.1249,y:103}).wait(1).to({graphics:mask_graphics_28,x:-2.1587,y:103}).wait(1).to({graphics:mask_graphics_29,x:6.7083,y:103}).wait(1).to({graphics:mask_graphics_30,x:16.2917,y:103}).wait(1).to({graphics:mask_graphics_31,x:25.1587,y:103}).wait(1).to({graphics:mask_graphics_32,x:33.1249,y:103}).wait(1).to({graphics:mask_graphics_33,x:40.2535,y:103}).wait(1).to({graphics:mask_graphics_34,x:46.6053,y:103}).wait(1).to({graphics:mask_graphics_35,x:52.2389,y:103}).wait(1).to({graphics:mask_graphics_36,x:57.2107,y:103}).wait(1).to({graphics:mask_graphics_37,x:61.5746,y:103}).wait(1).to({graphics:mask_graphics_38,x:65.3823,y:103}).wait(1).to({graphics:mask_graphics_39,x:68.6831,y:103}).wait(1).to({graphics:mask_graphics_40,x:71.5243,y:103}).wait(1).to({graphics:mask_graphics_41,x:73.2253,y:103}).wait(1).to({graphics:mask_graphics_42,x:74.2523,y:103}).wait(1).to({graphics:mask_graphics_43,x:75.1131,y:103}).wait(1).to({graphics:mask_graphics_44,x:75.8268,y:103}).wait(1).to({graphics:mask_graphics_45,x:76.4112,y:103}).wait(1).to({graphics:mask_graphics_46,x:76.8829,y:103}).wait(1).to({graphics:mask_graphics_47,x:77.2575,y:103}).wait(1).to({graphics:mask_graphics_48,x:77.5492,y:103}).wait(1).to({graphics:mask_graphics_49,x:77.7713,y:103}).wait(1).to({graphics:mask_graphics_50,x:77.936,y:103}).wait(1).to({graphics:mask_graphics_51,x:78.0539,y:103}).wait(1).to({graphics:mask_graphics_52,x:78.1351,y:103}).wait(1).to({graphics:mask_graphics_53,x:78.188,y:103}).wait(1).to({graphics:mask_graphics_54,x:78.2201,y:103}).wait(1).to({graphics:mask_graphics_55,x:78.2377,y:103}).wait(1).to({graphics:mask_graphics_56,x:78.2461,y:103}).wait(1).to({graphics:mask_graphics_57,x:78.2492,y:103}).wait(1).to({graphics:mask_graphics_58,x:78.25,y:103}).wait(1).to({graphics:mask_graphics_59,x:78.25,y:103}).wait(1));

	// Layer_1
	this.arrow = new lib.arrow_1();
	this.arrow.name = "arrow";
	this.arrow.setTransform(150,125,1,1,0,0,0,150,125);

	var maskedShapeInstanceList = [this.arrow];

	for(var shapedInstanceItr = 0; shapedInstanceItr < maskedShapeInstanceList.length; shapedInstanceItr++) {
		maskedShapeInstanceList[shapedInstanceItr].mask = mask;
	}

	this.timeline.addTween(cjs.Tween.get(this.arrow).wait(60));

	// Layer_4
	this.cta_copy = new lib.cta_copy();
	this.cta_copy.name = "cta_copy";
	this.cta_copy.setTransform(150,125,1,1,0,0,0,150,125);

	var maskedShapeInstanceList = [this.cta_copy];

	for(var shapedInstanceItr = 0; shapedInstanceItr < maskedShapeInstanceList.length; shapedInstanceItr++) {
		maskedShapeInstanceList[shapedInstanceItr].mask = mask;
	}

	this.timeline.addTween(cjs.Tween.get(this.cta_copy).wait(60));

	// Layer_5
	this.cta_bg = new lib.cta_bg();
	this.cta_bg.name = "cta_bg";
	this.cta_bg.setTransform(11.5,183);

	var maskedShapeInstanceList = [this.cta_bg];

	for(var shapedInstanceItr = 0; shapedInstanceItr < maskedShapeInstanceList.length; shapedInstanceItr++) {
		maskedShapeInstanceList[shapedInstanceItr].mask = mask;
	}

	this.timeline.addTween(cjs.Tween.get(this.cta_bg).wait(60));

	this._renderFirstFrame();

}).prototype = p = new cjs.MovieClip();
p.nominalBounds = new cjs.Rectangle(0,183,156.5,23);


(lib.copy1 = function(mode,startPosition,loop,reversed) {
if (loop == null) { loop = true; }
if (reversed == null) { reversed = false; }
	var props = new Object();
	props.mode = mode;
	props.startPosition = startPosition;
	props.labels = {};
	props.loop = loop;
	props.reversed = reversed;
	cjs.MovieClip.apply(this,[props]);

	// Layer_1
	this.copy1A = new lib.copy1A_1();
	this.copy1A.name = "copy1A";
	this.copy1A.setTransform(364,45,1,1,0,0,0,364,45);

	this.timeline.addTween(cjs.Tween.get(this.copy1A).wait(1));

	this._renderFirstFrame();

}).prototype = getMCSymbolPrototype(lib.copy1, new cjs.Rectangle(0,0,300,250), null);


// stage content:
(lib.MF_MAT_Q22022_Flex_LearnMore_HTML_BAN_300x250 = function(mode,startPosition,loop,reversed) {
if (loop == null) { loop = false; }
if (reversed == null) { reversed = false; }
	var props = new Object();
	props.mode = mode;
	props.startPosition = startPosition;
	props.labels = {};
	props.loop = loop;
	props.reversed = reversed;
	cjs.MovieClip.apply(this,[props]);

	this.actionFrames = [1];
	// timeline functions:
	this.frame_1 = function() {
		this.stop();
		
		stage.enableMouseOver(); 
		
		var self = this;
		var g = gsap;
		this.hit.cursor = "pointer";
		
		var highlightArr = [this.highlight.h1, this.highlight.h2];
		
		g.to(this.hit, {duration:.125, alpha:0});
		
		g.from(this.copy1, {duration:1, x:"-=50", alpha:0, ease:"power3.out"});
		//g.from(this.copy1.copy1B, {duration:1, x:"-=25", alpha:0, ease:"power3.out", delay:1});
		
		g.to(this.copy1, {duration:1, x:"+=50", alpha:0, ease:"power3.in", delay:3});
		g.from(this.copy2, {duration:1, x:"-=50", alpha:0, ease:"power3.out", delay:4});
		
		g.from(highlightArr, {duration:1, scaleX:0, ease:"power3.out", delay:5});
		
		g.delayedCall(6, function(){self.cta.gotoAndPlay(2)});
		
		g.to(this.cta.arrow, {duration:.25, x:"+=5", ease:"power1.inOut", delay:8});
		g.to(this.cta.arrow, {duration:.25, x:"-=5", ease:"power1.inOut", delay:8.25});
		g.to(this.cta.arrow, {duration:.25, x:"+=5", ease:"power1.inOut", delay:8.5});
		g.to(this.cta.arrow, {duration:.25, x:"-=5", ease:"power1.inOut", delay:8.75, onComplete:initRollover});
		
		
		
		function mouseOutHandler(e) {
			//
			console.log("cta out");
		};
		
		function mouseOverHandler(e) {
			canvas.removeEventListener("mouseover", mouseOverHandler);
			g.from(self.cta.arrow, {duration:.5, x:"-=25", alpha:0, ease:"power3.out", onComplete:function(){canvas.addEventListener("mouseover", mouseOverHandler, false)}});
			console.log("cta over");
		};
		
		function initRollover() {
			canvas.addEventListener("mouseover", mouseOverHandler, false);
			canvas.addEventListener("mouseout", mouseOutHandler, false);
		}
	}

	// actions tween:
	this.timeline.addTween(cjs.Tween.get(this).wait(1).call(this.frame_1).wait(1));

	// border
	this.shape = new cjs.Shape();
	this.shape.graphics.f("#000000").s().p("A3bTiIAA/FIAAn+MAu3AAAIAAH+IAAfFgA3RrjIAAe7MAujAAAIAA+7IAAn0MgujAAAg");
	this.shape.setTransform(150,125);

	this.timeline.addTween(cjs.Tween.get(this.shape).wait(2));

	// hit
	this.hit = new lib.hit();
	this.hit.name = "hit";
	this.hit.setTransform(150,125,1,1,0,0,0,150,125);

	this.timeline.addTween(cjs.Tween.get(this.hit).wait(2));

	// copy2
	this.copy2 = new lib.copy2_1();
	this.copy2.name = "copy2";
	this.copy2.setTransform(150,125,1,1,0,0,0,150,125);
	this.copy2._off = true;

	this.timeline.addTween(cjs.Tween.get(this.copy2).wait(1).to({_off:false},0).wait(1));

	// copy1
	this.copy1 = new lib.copy1();
	this.copy1.name = "copy1";
	this.copy1.setTransform(364,45,1,1,0,0,0,364,45);
	this.copy1._off = true;

	this.timeline.addTween(cjs.Tween.get(this.copy1).wait(1).to({_off:false},0).wait(1));

	// highlight
	this.highlight = new lib.highlight();
	this.highlight.name = "highlight";
	this.highlight._off = true;

	this.timeline.addTween(cjs.Tween.get(this.highlight).wait(1).to({_off:false},0).wait(1));

	// cta
	this.cta = new lib.cta_1();
	this.cta.name = "cta";
	this.cta.setTransform(150,125,1,1,0,0,0,150,125);
	this.cta._off = true;

	this.timeline.addTween(cjs.Tween.get(this.cta).wait(1).to({_off:false},0).wait(1));

	// bg
	this.instance = new lib.bg();
	this.instance.setTransform(0,0,0.5,0.5);

	this.timeline.addTween(cjs.Tween.get(this.instance).wait(2));

	this._renderFirstFrame();

}).prototype = p = new lib.AnMovieClip();
p.nominalBounds = new cjs.Rectangle(16.5,125,283.5,125);
// library properties:
lib.properties = {
	id: '2836400427BF4CF6BA11130227A937C1',
	width: 300,
	height: 250,
	fps: 60,
	color: "#FFFFFF",
	opacity: 1.00,
	manifest: [
		{src:"images/arrow.png?1649184358048", id:"arrow"},
		{src:"images/bg.png?1649184358048", id:"bg"},
		{src:"images/copy1A.png?1649184358048", id:"copy1A"},
		{src:"images/copy2.png?1649184358048", id:"copy2"},
		{src:"images/cta.png?1649184358048", id:"cta"}
	],
	preloads: []
};



// bootstrap callback support:

(lib.Stage = function(canvas) {
	createjs.Stage.call(this, canvas);
}).prototype = p = new createjs.Stage();

p.setAutoPlay = function(autoPlay) {
	this.tickEnabled = autoPlay;
}
p.play = function() { this.tickEnabled = true; this.getChildAt(0).gotoAndPlay(this.getTimelinePosition()) }
p.stop = function(ms) { if(ms) this.seek(ms); this.tickEnabled = false; }
p.seek = function(ms) { this.tickEnabled = true; this.getChildAt(0).gotoAndStop(lib.properties.fps * ms / 1000); }
p.getDuration = function() { return this.getChildAt(0).totalFrames / lib.properties.fps * 1000; }

p.getTimelinePosition = function() { return this.getChildAt(0).currentFrame / lib.properties.fps * 1000; }

an.bootcompsLoaded = an.bootcompsLoaded || [];
if(!an.bootstrapListeners) {
	an.bootstrapListeners=[];
}

an.bootstrapCallback=function(fnCallback) {
	an.bootstrapListeners.push(fnCallback);
	if(an.bootcompsLoaded.length > 0) {
		for(var i=0; i<an.bootcompsLoaded.length; ++i) {
			fnCallback(an.bootcompsLoaded[i]);
		}
	}
};

an.compositions = an.compositions || {};
an.compositions['2836400427BF4CF6BA11130227A937C1'] = {
	getStage: function() { return exportRoot.stage; },
	getLibrary: function() { return lib; },
	getSpriteSheet: function() { return ss; },
	getImages: function() { return img; }
};

an.compositionLoaded = function(id) {
	an.bootcompsLoaded.push(id);
	for(var j=0; j<an.bootstrapListeners.length; j++) {
		an.bootstrapListeners[j](id);
	}
}

an.getComposition = function(id) {
	return an.compositions[id];
}


an.makeResponsive = function(isResp, respDim, isScale, scaleType, domContainers) {		
	var lastW, lastH, lastS=1;		
	window.addEventListener('resize', resizeCanvas);		
	resizeCanvas();		
	function resizeCanvas() {			
		var w = lib.properties.width, h = lib.properties.height;			
		var iw = window.innerWidth, ih=window.innerHeight;			
		var pRatio = window.devicePixelRatio || 1, xRatio=iw/w, yRatio=ih/h, sRatio=1;			
		if(isResp) {                
			if((respDim=='width'&&lastW==iw) || (respDim=='height'&&lastH==ih)) {                    
				sRatio = lastS;                
			}				
			else if(!isScale) {					
				if(iw<w || ih<h)						
					sRatio = Math.min(xRatio, yRatio);				
			}				
			else if(scaleType==1) {					
				sRatio = Math.min(xRatio, yRatio);				
			}				
			else if(scaleType==2) {					
				sRatio = Math.max(xRatio, yRatio);				
			}			
		}
		domContainers[0].width = w * pRatio * sRatio;			
		domContainers[0].height = h * pRatio * sRatio;
		domContainers.forEach(function(container) {				
			container.style.width = w * sRatio + 'px';				
			container.style.height = h * sRatio + 'px';			
		});
		stage.scaleX = pRatio*sRatio;			
		stage.scaleY = pRatio*sRatio;
		lastW = iw; lastH = ih; lastS = sRatio;            
		stage.tickOnUpdate = false;            
		stage.update();            
		stage.tickOnUpdate = true;		
	}
}
an.handleSoundStreamOnTick = function(event) {
	if(!event.paused){
		var stageChild = stage.getChildAt(0);
		if(!stageChild.paused || stageChild.ignorePause){
			stageChild.syncStreamSounds();
		}
	}
}
an.handleFilterCache = function(event) {
	if(!event.paused){
		var target = event.target;
		if(target){
			if(target.filterCacheList){
				for(var index = 0; index < target.filterCacheList.length ; index++){
					var cacheInst = target.filterCacheList[index];
					if((cacheInst.startFrame <= target.currentFrame) && (target.currentFrame <= cacheInst.endFrame)){
						cacheInst.instance.cache(cacheInst.x, cacheInst.y, cacheInst.w, cacheInst.h);
					}
				}
			}
		}
	}
}


})(createjs = createjs||{}, AdobeAn = AdobeAn||{});
var createjs, AdobeAn;