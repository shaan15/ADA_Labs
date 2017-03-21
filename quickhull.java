import java.util.*;

public class Quickhull{

	public int crossproduct(Point a, Point b, Point c){
		int c= (b.x - a.x)*(c.y-a.y) - (b.y -a.y)*(c.x - a.x);
		if(c>0){
			return 0;
		}
		else if(c<0){
			return 1;
		}
		else{
			return 2;
		}
	}

	public int distance(Point a,Point b,Point c){
		int ans=(b.x-a.x)*(a.y-c.y)-(b.y-a.y)*(a.x-c.x);
		if(ans<0){
			return -ans;
		}
		else{
			return ans;
		}
	}

	public void find_hull(Point a, Point b, ArrayList<Point> li, ArrayList<Point> hull){
		int pos = hull.indexOf(b);
		int sz=li.size();
		int i;
		if(sz==0){
			return;
		} 
		else if(sz==1){
			Point po=li.get(0);
			hull.add(pos,po)''
			li.remove(po);
			return;

		}
		int dist=-100000000;
		int last=-1;
		for(i=0;i<sz;i++){
			Point po = li.get(i);
			int d = distance(a,b,po);
			if(d>dist){
				dist=d;
				last=i;
			}
		}

		Point A = li.get(last);
		hull.add(pos,A);
		li.remove(A);
        ArrayList<Point> left1 = new ArrayList<Point>();
        ArrayList<Point> left2 = new ArrayList<Point>();
        for(i=0;i<sz;i++){
        	Point mid = li.get(i);
        	if(crossproduct(a,b,mid) == 0){
        		left1.add(mid);
        		//added the convex point
        	}
        	if(crossproduct(A,b,mid) == 0){
        		left2.add(mid);
        	}
        }
        find_hull(a,A,left1,hull);
        find_hull(A,b,left2,hull);
	}
	//ArrayList<Point> l = new ArrayList<Point>();
	public ArrayList<Point> find_qh(ArrayList<Point> points){
		ArrayList<Point> ch = new ArrayList<Point>();
		int length_list = points.size();
		if(length_list<3){
			return (ArrayList)points.clone();
		}
		int min=-1, max=-1, lowest=-100000000, highest=100000000;
		int i;
		for(i=0;i<length_list;i++){
			int p=points.get(i).x
			if(p<lowest){
				lowest = p;
				min = i;
			}
			if(p>highest){
				highest = p;
				max=i;
			}
		}

		ArrayList<Point> left = new ArrayList<Point>();
		ArrayList<Point> right = new ArrayList<Point>();
		Point amin=points.get(min);
		Point amax=points.get(max);
		ch.add(amin);
		points.remove(amin);
		ch.add(amax);
		points.remove(amax);
		for(i=0;i<length_list;i++){
			Point pt = points.get(i);
			if(crossproduct(a,b,c) == 2){
				left.add(c);
			}
			else if(crossproduct(a,b,c) == 0){
				right.add(c);
			}
		}

		find_hull(a,b,right,ch);
		find_hull(b,a,left,ch);
		return ch;

	}
	public static void main(String args[])

    {

        System.out.println("Quick Hull Test");

        Scanner sc = new Scanner(System.in);

        System.out.println("Enter the number of points");

        int N = sc.nextInt();

 

        ArrayList<Point> points = new ArrayList<Point>();

        System.out.println("Enter the coordinates of each points: <x> <y>");

        for (int i = 0; i < N; i++)

        {

            int x = sc.nextInt();

            int y = sc.nextInt();

            Point e = new Point(x, y);

            points.add(i, e);

        }

 

        Quickhull qh = new Quickhull();

        ArrayList<Point> p = qh.quickHull(points);

        System.out.println("The points in the Convex hull using Quick Hull are: ");

        for (int i = 0; i < p.size(); i++)

            System.out.println("(" + p.get(i).x + ", " + p.get(i).y + ")");

        sc.close();

    }


}