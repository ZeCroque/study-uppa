"use strict";
//Déclaration de la machine à état
var statechartModel =
{
  states:
  [
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
          },
        ],
        transitions :
        [
          {
            event : 'stop',
            target : '$final'
          }
        ]
      },
      {
        id:'$final',
        $type:'final'
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

//Retourne les états actifs sans les états générés par défaut
function getActiveStates(itr)
{
  let temp=itr.getFullConfiguration();
  let result=[0];
  for(let i=0, j=0; i<temp.length; i++, j++)
  {
    if(temp[i][0]!='$')
    {
      result[j]=temp[i];
    }
    else
    {
      j--;
    }
  }
  return result;
}

if(scion!==undefined)
{
  //Déclaration
  var interpreter = new scion.Statechart(statechartModel);

  //Gestion des listeners
  window.addEventListener("load", function()
  {
    //Boutons
    let boutons=document.getElementsByClassName("request");
    let boutonStart = document.getElementById('start');
    let boutonStop = document.getElementById('stop');
    let consoleTextArea = document.getElementById('console');

    consoleTextArea.readOnly = true;
    consoleTextArea.scrollTop = document.getElementById("console").scrollHeight
    boutonStart.addEventListener('click', function(event)
    {
        interpreter.start();
        consoleTextArea.textContent+="\n      ACTIVE STATES : "+getActiveStates(interpreter);
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
        interpreter.gen({name : event.target.classList[1],data: event});
        consoleTextArea.textContent+="\n      ACTIVE STATES : "+getActiveStates(interpreter);
        consoleTextArea.scrollTop = consoleTextArea.scrollHeight ;
      });
    }

    interpreter.registerListener({onTransition:function(source, target, index)
    {
      if(source[0]!="$" && target[0]!="$")
      {
        consoleTextArea.textContent+="\n      ELIGIBLE TRANSITION :"+source+" -> "+target;
      }
    }});

    interpreter.registerListener({onEntry:function(stateId)
    {
      //Coloration
      let activeStates=document.getElementsByClassName(stateId);
      for (let i=0; i<activeStates.length; i++)
      {
        activeStates[i].classList.add("active");
        activeStates[i].classList.remove("inactive");
      }

      //Trace
      if(stateId[0]!="$")
      {
        consoleTextArea.textContent+="\n      ACTIVATED STATE :"+stateId;
      }
    }});
    interpreter.registerListener({onExit:function(stateId)
    {
      //Coloration
      let activeStates=document.getElementsByClassName(stateId);
      for (let i=0; i<activeStates.length; i++)
      {
        activeStates[i].classList.add("inactive");
        activeStates[i].classList.remove("active");
      }

      //Trace
      if(stateId[0]!="$")
      {
        consoleTextArea.textContent+="\n      DESACTIVATED STATE :"+stateId;
      }
    }});

  });
}
else
{
  console.log("Scion library was not loaded, nothing will work.")
}
