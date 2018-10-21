/**
 * Character.js
 */

'use strict';

var Character = function (image /* Image */) {
    chai.assert.isTrue(image !== undefined && image !== null && image instanceof Image && image.complete, 'Character._image');
    this._image = image;
//      Size of images must be changed so that feature detection algorithms work better...
    if (image.width / image.height < 0.9) {
        this._image.width = Math.max(this._image.width, this._image.height, 256);
        this._image.height = Math.max(this._image.width, this._image.height, 256);
    } else {
        if (image.height / image.width < 0.9) {
            this._image.width = Math.min(this._image.width, this._image.height);
            this._image.height = Math.min(this._image.width, this._image.height);
        }
    }
    /** Eyes */
    this._eyes = null; // Computed by Tracking.js
    /** Face */
    this._face = null; // Computed by Tracking.js
    /** Mouth */
    this._mouth = null; // Computed by Tracking.js
    /** GENERAL NOTES: detection results differ between Firefox and Chrome! */
    /**                changing 'tracking.js' parameters gives poor results */
    this._features_detection_ready = Promise.all([new Promise(function (ready) {
            let tracker = new tracking.ObjectTracker(['eye']);
            tracker.setInitialScale(1.);
            tracker.setStepSize(1.);
            tracker.setEdgesDensity(0.1);
            tracker.on('track', event => {
                this._eyes = event.data;
                ready();
            });
            tracking.track(this._image, tracker);
        }.bind(this)), new Promise(function (ready) {
            let tracker = new tracking.ObjectTracker(['face']);
            tracker.setInitialScale(1.);
            tracker.setStepSize(1.);
            tracker.setEdgesDensity(0.1);
            tracker.on('track', function (event) {
                this._face = event.data;
                ready();
            }.bind(this));
            tracking.track(this._image, tracker);
        }.bind(this)), new Promise(function (ready) {
            let tracker = new tracking.ObjectTracker(['mouth']);
            tracker.setInitialScale(1.);
            tracker.setStepSize(1.);
            tracker.setEdgesDensity(0.1);
            tracker.on('track', function (event) {
                this._mouth = event.data;
                ready();
            }.bind(this));
            tracking.track(this._image, tracker);
        }.bind(this))]).then(function () {

        /** Post-processing */
        if (this._face !== null && this._face.length > 1) {
// Attention, plusieurs faces ont pu être calculées...
        }
        // Bouche la plus basse sur la photo mais ne tient pas compte que la bouche est incluse dans la face (voir Macron !) :
        if (this._mouth !== null && this._mouth.length > 1)
            this._mouth.sort(function (mouth1, mouth2) {
                return mouth2.y - mouth1.y;
            }).splice(1, this._mouth.length - 1);
		if (this._eyes !== null && this._eyes.length > 2)
		{
			for(let i=0; i<this._eyes.length; i++)
			{
				if(this._eyes[i].x<this._face[0].x || this._eyes[i].x>this._face[0].width+this._face[0].x)
				{
					this._eyes.splice(i, 1); 
				}
			}

			let delta=0;
			let iMin=0;
			let jMin=0;
			for(let i=0; i<this._eyes.length; i++)
			{
				for(let j=i+1; j<this._eyes.length; j++)
				{
					if(delta==0 || Math.abs(this._eyes[i].y-this._eyes[j].y)<delta)
					{
						delta=Math.abs(this._eyes[i].y-this._eyes[j].y);
						console.log("i:"+i+"j:"+j+"d:"+delta);
						iMin=i;
						jMin=j;
					}
				}
			}
			let tmp = [this._eyes[iMin], this._eyes[jMin]]
			this._eyes=tmp;

			
			
		}

        /** Fin du post-processing */

        let canvas = document.createElement("CANVAS");
        canvas.width = this._image.width;
        canvas.height = this._image.height;
        canvas.getContext('2d').drawImage(this._image, 0, 0, this._image.width, this._image.height);
        canvas.getContext('2d').lineWidth = 1;
        canvas.getContext('2d').strokeStyle = 'red';
        for (var i = 0; i < this._eyes.length; ++i) {
            canvas.getContext('2d').strokeRect(Math.round(this._eyes[i].x), Math.round(this._eyes[i].y), Math.round(this._eyes[i].width), Math.round(this._eyes[i].height));
        }
        canvas.getContext('2d').strokeStyle = 'blue';
        for (var i = 0; i < this._face.length; ++i) {
            canvas.getContext('2d').strokeRect(Math.round(this._face[i].x), Math.round(this._face[i].y), Math.round(this._face[i].width), Math.round(this._face[i].height));
        }
        canvas.getContext('2d').strokeStyle = 'green';
        for (var i = 0; i < this._mouth.length; ++i) {
            canvas.getContext('2d').strokeRect(Math.round(this._mouth[i].x), Math.round(this._mouth[i].y), Math.round(this._mouth[i].width), Math.round(this._mouth[i].height));
        }
        canvas.style.width = "250px";
        canvas.style.height = "250px";
        document.getElementById('Feature_detection').insertBefore(canvas, document.getElementById('Feature_detection').childNodes[0]);
    }.bind(this));
};

