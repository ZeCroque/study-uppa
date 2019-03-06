/*
 * Feature_detection.js
 */

'use strict';

// DOM ready:
Object.defineProperty(window, "_DOM_is_usable", {value: null, enumerable: false, configurable: false, writable: true});
new Promise(function_launched_when_DOM_is_usable => {
    _DOM_is_usable = function_launched_when_DOM_is_usable;
}).then(value => {// Anonymous function as parameter of 'then'. This function has itself 'value' as parameter...
    chai.assert.isTrue(value instanceof Event, 'value instanceof Event');
    chai.assert.strictEqual(value.type, "readystatechange", 'value.type === "readystatechange"');
    chai.assert.isTrue(document.readyState === "interactive", 'Strange? \'document.readyState\' is NOT properly set up...')
//        alert('\'document.readyState\' is: ' + document.readyState);

    let Franck = new Image();
    Franck.onload = function () {
        new Character(Franck);
    };
    Franck.src = "img/Franck.jpg";

    let Oscar = new Image();
    Oscar.onload = function () {
        new Character(Oscar);
    };
    Oscar.src = "img/Oscar.jpg";

    let Macron = new Image();
    Macron.onload = function () {
        new Character(Macron);
    };
    Macron.src = "img/Macron.jpeg";

    let Philippe = new Image();
    Philippe.onload = function () {
        new Character(Philippe);
    };
    Philippe.src = "img/Philippe.jpg";

    let Bayrou = new Image();
    Bayrou.onload = function () {
        new Character(Bayrou);
    };
    Bayrou.src = "img/Bayrou.jpg";

    let LePen = new Image();
    LePen.onload = function () {
        new Character(LePen);
    };
    LePen.src = "img/LePen.jpg";

    let Melanchon = new Image();
    Melanchon.onload = function () {
        new Character(Melanchon);
    };
    Melanchon.src = "img/Melanchon.jpg";
});
document.onreadystatechange = _DOM_is_usable;

// Window loaded:
Object.defineProperty(window, "_Window_is_loaded", {value: null, enumerable: false, configurable: false, writable: true});
Object.defineProperty(window, "Window_is_loaded", {value: new Promise(function_launched_when_Window_is_loaded => {
        _Window_is_loaded = function_launched_when_Window_is_loaded;
    }).then(value => {// Anonymous function as parameter of 'then'. This function has itself 'value' as parameter...
        chai.assert.isTrue(value instanceof Event, 'value instanceof Event');
        chai.assert.strictEqual(value.type, "load", 'value.type === "load"');
        chai.assert.strictEqual(document.readyState, "complete", 'Strange? \'document.readyState\' is NOT properly set up...');
//    alert('\'document.readyState\' is: ' + document.readyState);
//    alert("window.innerWidth: " + window.innerWidth + " window.innerHeight: " + window.innerHeight);
    }), enumerable: false, configurable: false, writable: true});
window.addEventListener('load', _Window_is_loaded);
