"use strict";

//Déclaration de la machine à état
var statechartModel =
{
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
            id : 'busy_parallel',
            $type:'parallel',

            states:
            [
              {
                id : 'busy',
                transitions :
                [
                    {
                        event : 'e',
                        target : 'idle'
                    },
                    {
                        event : 'c1',
                        target : 'S22',
                    }
                ]
              },
              {
                id : 'S1',
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
                    $type : 'initial',
                  },
                  {
                    id : 'S12',
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
                states:
                [
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
                  {
                    id : 'S22',
                    $type : 'initial',
                  }
                ]
              },
              {
                id : 'S3_parallel',
                $type : 'parallel',
                states:
                [
                  {
                    id: 'S3',
                    transitions :
                    [
                        {
                            event : 'b',
                            target : 'S12'
                        },
                        {
                            event : 'c',
                            target : 'S12',
                        }
                    ]

                  },
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
                    id : 'S32'
                  }
                ]
              }
            ]
        }
    ]
};


if(scion!==undefined)
{
  //Déclaration
  var interpreter = new scion.Statechart(statechartModel);

  //Gestion des listeners
  window.addEventListener("load", function()
  {
    var i=0;

    let boutons=document.getElementsByClassName("boutonRequest");

    let boutonStart = document.getElementById('start');
    let boutonC = document.getElementById('c');

    boutonStart.addEventListener('click', function(event)
    {
        interpreter.start();
    });

    boutonC.addEventListener('click', function(event)
    {
      interpreter.gen({name : "h",data: event});
    });

    boutonC.addEventListener('click', function(event)
    {
      interpreter.gen({name : "c1",data: event});
    });

    interpreter.registerListener({onTransition:function(source, target, index)
    {
      console.log("source :"+source+"\ntarget :"+target);
    }});

    for(let i=0; i<boutons.length; i++)
    {

      boutons[i].addEventListener("click",function(event)
      {
        console.log(interpreter.getConfiguration());

        interpreter.gen({name : event.target.id,data: event});
      });
    }
  });
}
else
{
  console.log("Scion library was not loaded, nothing will work.")
}

