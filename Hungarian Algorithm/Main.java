import java.util.Scanner;

public class Main
{
    private static final int mn = 300, maxC = 1000006;
    private static int n, co = 0, numX, numY;
    private static int[] fx = new int[mn], fy = new int[mn], trace = new int[mn];
    private static int[] matchX = new int[mn], matchY = new int[mn], inReachY = new int[mn];
    private static int[] reachX = new int[mn], reachY = new int[mn], queue = new int[mn];
    private static int[][] c = new int[mn][mn];

    private static int C(int x, int y) {return c[x][y] - fx[x] - fy[y];}

    private static int findArgumentPath(int x)
    {
        co ++;
        numX = numY = 0;
        int l = 1, r = 1;
        queue[l] = x;
        while(l <= r)
        {
            int u = queue[l ++];
            reachX[++ numX] = u;
            for(int v = 1; v <= n; v ++)
            if (inReachY[v] != co && C(u, v) == 0)
            {
                inReachY[v] = co;
                reachY[++ numY] = v;
                trace[v] = u;
                if (matchY[v] == 0)
                    return v;
                queue[++ r] = matchY[v];
            }
        }
        return 0;
    }

    private static void changeEdge()
    {
        int delta = maxC;
        for(int i = 1; i <= numX; i ++)
        {
            int u = reachX[i];
            for(int v = 1; v <= n; v ++)
                if (inReachY[v] != co && delta > C(u, v))
                    delta = C(u, v);

        }

        for(int i = 1; i <= numX; i ++)
            fx[reachX[i]] += delta;
        for(int i = 1; i <= numY; i ++)
            fy[reachY[i]] -= delta;
    }

    private static void argumenting(int y)
    {
        while(inReachY[y] == co)
        {
            int x = trace[y];
            int nex = matchX[x];
            matchX[x] = y;
            matchY[y] = x;
            y = nex;
        }
    }

    private static void enter()
    {
        Scanner s = new Scanner(System.in);
        n = s.nextInt();
        for(int u = 1; u <= n; u ++)
        for(int v = 1; v <= n; v ++)
            c[u][v] = maxC;
        while(s.hasNext())
        {
            int u = s.nextInt();
            int v = s.nextInt();
            c[u][v] = s.nextInt();
        }
    }

    private static void solve()
    {
        for(int x = 1; x <= n; x ++)
        while(true)
        {
            int y = findArgumentPath(x);
            if (y == 0)
                changeEdge();
            else
            {
                argumenting(y);
                break;
            }
        }
    }

    private static void print()
    {
        int ans = 0;
        for(int x = 1; x <= n; x ++)
            ans += c[x][matchX[x]];
        System.out.print(ans + "\n");
        for(int x = 1; x <= n; x ++)
            System.out.print(x + " " + matchX[x] + "\n");
    }

    public static void main(String[] args)
    {
        enter();
        solve();
        print();
    }
}
