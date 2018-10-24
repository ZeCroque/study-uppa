"use strict";

//Déclaration de la machine à état
var statechartModel =
{
    states :
    [
        {
            id : 'idle',
            onEntry : function()
            {
                console.log("1");
            },
            transitions :
            [
                {
                    event : 'click',
                    target : 'clicked',
                    onTransition : function(event)
                    {                      }
                }
            ]
        },
        {
            id : 'clicked',
            onEntry : function()
            {
                console.log("2");
            },
            /*transitions :
            [
                {
                    event : 'mouseup',
                    target : 'idle'
                },
                {
                    event : 'mousemove',
                    target : 'dragging',
                    onTransition : function(event)
                    {
                        var dx = eventStamp.clientX - event.data.clientX;
                        var dy = eventStamp.clientY - event.data.clientY;

                        rectNode.style.left = (rectX -= dx) + 'px';
                        rectNode.style.top = (rectY -= dy) + 'px';

                        eventStamp = event.data;
                    }
                }
            ]*/
        }
    ]
};

//Déclaration & lancement de l'interpréteur
var interpreter = new scion.Statechart(statechartModel);
interpreter.start();

//Gestion des listeners
window.addEventListener("load", function()
{


  let bouton = document.getElementById('boutonTest');
  let texte = document.getElementById('texteCache')
  bouton.addEventListener('click', function(event)
  {
    interpreter.gen({name : event.type,data: event});
  });
});
