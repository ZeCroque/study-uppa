
import java.util.Random;

import javafx.scene.shape.LineTo;
import javafx.scene.shape.MoveTo;
import javafx.scene.shape.Path;
import javafx.util.Pair;

public class Route
{
	
	//STATIC
	private static Pair<Integer,Integer> startPoint;
	private static Pair<Integer,Integer> endPoint;
	
	private static Pair<Integer, Integer> genCoord()
	{
		Random rand = new Random();
		return new Pair<>(rand.nextInt(10),rand.nextInt(10));
	}
	
	private static void genCoords()
	{
		do
		{
			Route.startPoint=Route.genCoord();
			Route.endPoint=Route.genCoord();
		} while(Route.startPoint.equals(Route.endPoint));
	}
	
	//INSTANCE
	public Path path;
	
	public Route()
	{
		if(Route.startPoint==null)
		{
			Route.genCoords();
		}
		this.path=new Path();
	}
		
	public void genPath(double width, double height)
	{
		Random rand = new Random();
		int i=Route.startPoint.getKey();
		int j=Route.startPoint.getValue();

		this.path.setOpacity(1);
		do
		{
			int coinFlip=rand.nextInt(2);
			int iTarget=i;
			int jTarget=j;
			double x=(width-height)/2+10+i*((height-20)/10);
			double y=j*((height-20)/10)+10;
			
			this.path.getElements().add(new MoveTo(x,y));
			if((coinFlip==0 && i!=Route.endPoint.getKey()) || (coinFlip==1 && j==Route.endPoint.getValue()))
			{
				if(i<Route.endPoint.getKey())
				{
					iTarget+=rand.nextInt(Route.endPoint.getKey()-i)+1;
					this.path.getElements().add(new LineTo(x+(height/10)*(iTarget-i),y));
				}
				else
				{
					iTarget-=rand.nextInt(i-Route.endPoint.getKey())+1;
					this.path.getElements().add(new LineTo(x-(height/10)*(i-iTarget),y));
				}

			}
			else if ((coinFlip==1 && j!=Route.endPoint.getValue()) || (coinFlip==0 && i==Route.endPoint.getKey()))
			{
				if(j<Route.endPoint.getValue())
				{
					jTarget+=rand.nextInt(Route.endPoint.getValue()-j)+1;
					this.path.getElements().add(new LineTo(x,y+(height/10)*(jTarget-j)));

				}
				else
				{
					jTarget-=rand.nextInt(j-Route.endPoint.getValue())+1;
					this.path.getElements().add(new LineTo(x,y-(height/10)*(j-jTarget)));
				}
				
			}
			i=iTarget;
			j=jTarget;
			

		} while(i!=Route.endPoint.getKey() || j!=Route.endPoint.getValue());
	}
}

