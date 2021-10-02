import java.io.*;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Main {

    static int[] computer;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());

        ArrayList<Integer>[] list = new ArrayList[N + 1];

        for (int i = 1; i <= N; i++) {
            list[i] = new ArrayList<>();
        }

        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());

            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());

            list[a].add(b);
        }

        computer = new int[N + 1];
        int max = Integer.MIN_VALUE;
        for (int i = 1; i <= N; i++) {
            boolean[] visited = new boolean[N + 1];
            dfs(i, visited, list);
        }

        for (int i = 1; i <= N; i++) {
            max = Math.max(max, computer[i]);
        }

        for (int i = 1; i <= N; i++) {
            if (computer[i] == max) {
                bw.write(i + " ");
            }
        }

        bw.flush();
        bw.close();
    }

    public static void dfs(int start, boolean[] visited, ArrayList<Integer>[] list) {
        visited[start] = true;
        for (int node : list[start]) {
            if (!visited[node]) {
                computer[node]++;
                dfs(node, visited, list);
            }
        }
    }

}