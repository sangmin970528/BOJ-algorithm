import java.io.*;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Main {

    static char[] arr = new char[10];
    static boolean[] visited = new boolean[10];
    static int k;
    static ArrayList<String> answer = new ArrayList<>();
    static String temp = "";

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        k = Integer.parseInt(br.readLine());
        String str = br.readLine();
        StringTokenizer st = new StringTokenizer(str, " ");
        for (int i = 0; i < k; i++) {
            arr[i] = st.nextToken().charAt(0);
        }
        for (int i = 0; i <= 9; i++) {
            visited[i] = true;
            temp += Integer.toString(i);
            backtracking(1, 0, i);
            temp = temp.substring(0, temp.length() - 1);
            visited[i] = false;
        }
        System.out.println(answer.get(answer.size() - 1));
        System.out.println(answer.get(0));
    }

    public static void backtracking(int length, int x, int before) {
        if (length == k + 1) {
            answer.add(temp);
            return;
        }
        for (int i = 0; i <= 9; i++) {
            if (visited[i] == false) {
                if (arr[x] == '<') {
                    if (before < i) {
                        visited[i] = true;
                        temp += Integer.toString(i);
                        backtracking(length + 1, x + 1, i);
                        temp = temp.substring(0, temp.length() - 1);
                        visited[i] = false;
                    }
                } else {
                    if (before > i) {
                        visited[i] = true;
                        temp += Integer.toString(i);
                        backtracking(length + 1, x + 1, i);
                        temp = temp.substring(0, temp.length() - 1);
                        visited[i] = false;
                    }
                }
            }
        }
    }
}
