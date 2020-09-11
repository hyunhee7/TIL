package programmers;

import java.io.IOException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;

public class p41888_오픈채팅방 {
    public static String[] solution(String[] record) {
        String[] answer = {};
        ArrayList<String> tmp = new ArrayList<>();
        Map<String, String> uuid = new HashMap<>();
        for(String line : record){
            String[] val = line.split(" ");
            if(val[0].equals("Enter")){
                uuid.put(val[1],val[2]);
            }
            else if(val[0].equals("Change")){
                uuid.replace(val[1],val[2]);
            }
        }
        for(String line : record){
            String[] val = line.split(" ");
            if(val[0].equals("Enter")){
                tmp.add(uuid.get(val[1])+"님이 들어왔습니다.");
            }else if(val[0].equals("Leave")){
                tmp.add(uuid.get(val[1])+"님이 나갔습니다.");
            }
        }
        answer = tmp.toArray(new String[tmp.size()]);
        return answer;
    }
    public static void main(String[] args) throws IOException {
        String[] record = {
                "Enter uid1234 Muzi", "Enter uid4567 Prodo", "Leave uid1234", "Enter uid1234 Prodo", "Change uid4567 Ryan"
        };
        System.out.println(solution(record).toString());
    }
}
