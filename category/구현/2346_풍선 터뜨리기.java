import java.io.*;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int N = Integer.parseInt(br.readLine());
        String str = br.readLine();
        ArrayList<Integer> arr = new ArrayList<>();
        ArrayList<Integer> answer = new ArrayList<>();
        StringTokenizer st = new StringTokenizer(str, " ");
        for (int i = 0; i < N; i++) {
            arr.add(Integer.parseInt(st.nextToken()));
        }

        int num = arr.get(0);
        int idx = 0;
        answer.add(idx + 1);
        arr.set(idx, 0);
        while (answer.size() != arr.size()) {
            if (num > 0) {
                for (int i = 0; i < num; i++) {
                    idx++;
                    if (idx > arr.size() - 1)
                        idx = 0;
                    if (arr.get(idx) == 0)
                        i--;
                }
            } else {
                for (int i = 0; i > num; i--) {
                    idx--;
                    if (idx < 0)
                        idx = arr.size() - 1;
                    if (arr.get(idx) == 0)
                        i++;
                }
            }
            num = arr.get(idx);
            answer.add(idx + 1);
            arr.set(idx, 0);
        }
        for (Integer index : answer) {
            bw.write(Integer.toString(index) + " ");
        }
        bw.flush();
    }
}
