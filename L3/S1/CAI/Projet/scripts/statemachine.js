"use strict";

var boutonTest;
var boutonCache;

//Déclaration de la machine à état
var statechartModel =
{
    states :
    [
        {
            id : 'idle',
            onEntry : function()
            {
                boutonCache.style="display:none";
                console.log("idle");
            },
            transitions :
            [
                {
                    event : 'go',
                    target : ['S22', 'S31', 'S32', 'S11'],
                    onTransition : function(event)
                    {}
                }
            ]
        },
        {
            id : 'busy',
            transitions :
            [
                {
                    event : 'e',
                    target : 'idle'
                },
                {
                    event : 'c',
                    target : 'S22'
                }
            ],
            states:
            [
              {
                id : 'S1',
                onEntry : function()
                {
                    console.log("S1");
                },
                transitions:
                [
                  {
                      event : 'd',
                      target : 'S21'
                  }
                ],
                states:
                [
                  {
                    id : 'S11',
                    onEntry : function()
                    {
                        console.log("S11");
                    }
                  },
                  {
                    id : 'S12',
                    onEntry : function()
                    {
                        console.log("S12");
                    },
                    transitions :
                    [
                      {
                        event : 'g',
                        target : 'S11'
                      }
                    ]
                  }
                ]
              },
              {
                id : 'S2',
                onEntry : function()
                {
                    console.log("S2");
                },
                states:
                [
                  {
                    id : 'S21',
                    onEntry : function()
                    {
                        console.log("S21");
                    },
                    transitions :
                    [
                        {
                            event : 'f',
                            target : 'idle'
                        }
                    ]
                  },
                  {
                    id : 'S22',
                    onEntry : function()
                    {
                      //interpreter.gen("h");
                    }
                  }
                ]
              },
              {
                id : 'S3',
                onEntry : function()
                {
                    console.log("S3");
                },
                states:
                [
                  {
                    id : 'S31',
                    onEntry : function()
                    {
                        console.log("S31");
                    },
                    transitions :
                    [
                        {
                            event : 'h',
                            target : 'S31'
                        }
                    ]
                  },
                  {
                    id : 'S32',
                    onEntry : function()
                    {
                        console.log("S32");
                    }
                  }
                ],
                transitions :
                [
                    {
                        event : ['b','c'],
                        target : 'S12'
                    }
                ]
              }
            ]
        }
    ]
};

if(scion!==undefined)
{
  //Déclaration & lancement de l'interpréteur
  var interpreter = new scion.Statechart(statechartModel);
  interpreter.start();

  //Gestion des listeners
  window.addEventListener("load", function()
  {
    boutonTest = document.getElementById('boutonTest');
    boutonCache = document.getElementById('boutonCache')
    boutonTest.addEventListener('click', function(event)
    {
      interpreter.gen({name : "go",data: event});
    });
    boutonCache.addEventListener('click', function(event)
    {
      interpreter.gen({name : "",data: event});
    });
  });
}
else
{
  console.log("Scion library was not loaded, nothing will work.")
}

