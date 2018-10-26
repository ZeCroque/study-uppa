"use strict";
//Déclaration de la machine à état
var statechartModel =
{
    id : 'mydevice',
    states :
    [
        {
            id : 'idle',
            $type:'initial',
            transitions :
            [
                {
                    event : 'go',
                    target : 'busy',
                }
            ]
        },
        {
            id : 'busy',
            $type:'parallel',
            transitions :
            [
                {
                    event : 'e',
                    target : 'idle'
                },
                {
                    event : 'c',
                    target : 'S22',
                }
            ],
            states:
            [
              {
                id : 'S1',
                transitions:
                [
                  {
                      event : 'd',
                      target : 'S21'
                  },
                  {
                      event : 'b',
                      target : 'S12'
                  }
                ],
                states:
                [
                  {
                    id : 'S11',
                    onEntry : function(event)
                    {
                      console.log("w");
                    },
                    onExit : function(event)
                    {
                      console.log("x")
                    }
                  },
                  {
                    id : 'S12',
                    transitions :
                    [
                      {
                        event : 'g',
                        target : 'S11'
                      }
                    ],
                    onEntry : function(event)
                    {
                      console.log("y");
                    },
                    onExit : function(event)
                    {
                      console.log("z")
                    }
                  }
                ]
              },
              {
                id : 'S2',
                states:
                [
                  {
                    id : 'S22',
                    onEntry : function(event)
                    {
                        //this.send({name: "h", data:event});
                        cEvent=undefined;
                    }
                  },
                  {

                    id : 'S21',
                    transitions :
                    [
                        {
                            event : 'f',
                            target : 'idle'
                        }
                    ]
                  },

                ]
              },
              {
                id : 'S3',
                $type : 'parallel',
                transitions :
                [
                    {
                        event : 'c',
                        target : 'S12',
                    }
                ],
                states:
                [
                  {
                    id : 'S31',
                    transitions :
                    [
                        {
                          event : 'h',
                          target : 'S31',
                          onTransition:function(event)
                          {
                            console.log("a");
                          }
                        }
                    ]
                  },
                  {
                    id : 'S32',
                    onEntry:function(event)
                    {
                      port.listenTo();
                    }
                  }
                ]
              }
            ]
        }
    ]
};

//Fakeport
var port =
{
  listenTo : function()
  {
    console.log("I'm listening");
  }
};


if(scion!==undefined)
{
  //Déclaration
  var interpreter = new scion.Statechart(statechartModel);

  //Gestion des listeners
  window.addEventListener("load", function()
  {
    //Boutons
    let boutons=document.getElementsByClassName("boutonRequest");
    let boutonStart = document.getElementById('start');
    let boutonStop = document.getElementById('stop');
    let consoleTextArea = document.getElementById('console');

    boutonStart.addEventListener('click', function(event)
    {
        interpreter.start();
        consoleTextArea.textContent+="\n"+interpreter.getFullConfiguration();
        document.body.style.backgroundImage="url('./Ressources/backgroundON.jpeg')" ;
    });

    boutonStop.addEventListener('click', function(event)
    {
        document.body.style.backgroundImage="url('./Ressources/backgroundOFF.jpeg')" ;
    });


    for(let i=0; i<boutons.length; i++)
    {

      boutons[i].addEventListener("click",function(event)
      {
        interpreter.gen({name : event.target.classList[0],data: event});
        consoleTextArea.textContent+="\n"+interpreter.getFullConfiguration();
      });
    }

    interpreter.registerListener({onTransition:function(source, target, index)
    {
      consoleTextArea.textContent+="\nsource :"+source+"\ntarget :"+target;
    }});

    interpreter.registerListener({onEntry:function(stateId)
    {
      let activeStates=document.getElementsByClassName(stateId);
      for (let i=0; i<activeStates.length; i++)
      {
        activeStates[i].classList.remove("inactive");
        activeStates[i].classList.add("active");
      }
    }});
    interpreter.registerListener({onExit:function(stateId)
    {
      let activeStates=document.getElementsByClassName(stateId);
      for (let i=0; i<activeStates.length; i++)
      {
        activeStates[i].classList.add("inactive");
        activeStates[i].classList.remove("active");
      }
    }});

  });
}
else
{
  console.log("Scion library was not loaded, nothing will work.")
}
