"use strict";


//Déclaration de la machine à état
var statechartModel =
{
    states :
    [
        {
            id : 'idle',
            $type:'initial',
            onEntry : function()
            {
                console.log("idle");
            },
            transitions :
            [
                {
                    event : 'go',
                    target : ['busy'],
                    onTransition : function(event)
                    {}
                }
            ]
        },
        {
            id : 'busy',
            $type : 'parallel',
            onEntry : function()
            {
                console.log("busy");
            },
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
                    $type : 'initial',
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
                    $type : 'initial',
                    onEntry : function()
                    {
                      console.log("S22");
                      interpreter.gen("h");
                    }
                  }
                ]
              },
              {
                id : 'S3',
                $type : 'parallel',
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
                        event : 'b',
                        target : 'S12'
                    },
                    {
                        event : 'c',
                        target : 'S12',
                    }
                ]
              }
            ],
            transitions :
            [
                {
                    event : 'b',
                    target : 'S12'
                },
                {
                    event : 'c',
                    target : 'S22',
                    onTransition:function(event)
                    {
                      console.log("a");
                    }
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
    let boutons=document.querySelectorAll("input[type=button]");

    let boutonStart = document.getElementById('boutonStart');
    let boutonGo = document.getElementById('boutonGo');
    let boutonC = document.getElementById('boutonC');

    boutonStart.addEventListener('click', function(event)
    {
        interpreter.start();
    });
    boutonGo.addEventListener('click', function(event)
    {
      interpreter.gen({name : "go",data: event});
    });

    boutonC.addEventListener('click', function(event)
    {
      interpreter.gen({name : "c",data: event});
    });

    interpreter.registerListener({onTransition:function(source, target, index)
    {
      console.log("source :"+source+"\ntarget :"+target);
    }});

    for(let i=0; i<boutons.length; i++)
    {
      boutons[i].addEventListener("click",function()
      {
        console.log(interpreter.getConfiguration());
      });
    }
  });
}
else
{
  console.log("Scion library was not loaded, nothing will work.")
}

