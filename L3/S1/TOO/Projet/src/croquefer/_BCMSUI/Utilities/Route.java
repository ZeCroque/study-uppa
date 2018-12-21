package croquefer._BCMSUI.Utilities;

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
	private static final int roadSizeMax=200;
	private static final double distanceMin=170;
	private static final int padding=10;

	
	private static double getDistance(Pair<Integer,Integer> startPoint, Pair<Integer,Integer> endPoint)
	{
		return Math.sqrt(Math.pow(Route.endPoint.getKey()-Route.startPoint.getKey(),2)+Math.pow(Route.endPoint.getValue()-Route.startPoint.getValue(),2));
	}
	
	private static Pair<Integer, Integer> genCoord()
	{
		Random rand = new Random();
		return new Pair<>(rand.nextInt(Route.roadSizeMax-Route.padding+1)+Route.padding,rand.nextInt(Route.roadSizeMax-Route.padding+1)+Route.padding);
	}
	
	private static void genCoords()
	{
		do
		{
			Route.startPoint=Route.genCoord();
			Route.endPoint=Route.genCoord();
		} while(Route.startPoint.equals(Route.endPoint) || Route.getDistance(startPoint, endPoint)<Route.distanceMin);
	}
	
	public static void resetCoords()
	{
		Route.startPoint=null;
		Route.endPoint=null;
	}
	
	//INSTANCE
	private Path path;
	
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
			double x=(width-height)/2+i*(height/Route.roadSizeMax);
			double y=j*(height/Route.roadSizeMax);
			
			this.path.getElements().add(new MoveTo(x,y));
			if((coinFlip==0 && i!=Route.endPoint.getKey()) || (coinFlip==1 && j==Route.endPoint.getValue()))
			{
				if(i<Route.endPoint.getKey())
				{
					iTarget+=rand.nextInt(Route.endPoint.getKey()-i)+1;
					this.path.getElements().add(new LineTo(x+(height/Route.roadSizeMax)*(iTarget-i),y));
				}
				else
				{
					iTarget-=rand.nextInt(i-Route.endPoint.getKey())+1;
					this.path.getElements().add(new LineTo(x-(height/Route.roadSizeMax)*(i-iTarget),y));
				}

			}
			else if ((coinFlip==1 && j!=Route.endPoint.getValue()) || (coinFlip==0 && i==Route.endPoint.getKey()))
			{
				if(j<Route.endPoint.getValue())
				{
					jTarget+=rand.nextInt(Route.endPoint.getValue()-j)+1;
					this.path.getElements().add(new LineTo(x,y+(height/Route.roadSizeMax)*(jTarget-j)));

				}
				else
				{
					jTarget-=rand.nextInt(j-Route.endPoint.getValue())+1;
					this.path.getElements().add(new LineTo(x,y-(height/Route.roadSizeMax)*(j-jTarget)));
				}
				
			}
			i=iTarget;
			j=jTarget;
			

		} while(i!=Route.endPoint.getKey() || j!=Route.endPoint.getValue());
	}
	
	public Path getPath()
	{
		return this.path;
	}
	
	public static Pair<Integer,Integer> getStartPoint()
	{
		return startPoint;
	}
	
	public static Pair<Integer,Integer> getEndPoint()
	{
		return endPoint;
	}
}

