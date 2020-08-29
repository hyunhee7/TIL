package programmers;
import java.util.*;
public class p49993_스킬트리 {
    public static int solution2(String skill, String[] skill_trees) {
        int answer = 0;
        ArrayList<String> skillTrees = new ArrayList<>(Arrays.asList(skill_trees));
        Iterator<String> it = skillTrees.iterator();

        while(it.hasNext()){
            if(skill.indexOf(it.next().replaceAll("[^"+skill+"]",""))!=0){
                it.remove();
            }
        }
        return answer;
    }

    public static int solution(String skill, String[] skill_trees) {
        int answer = 0;
        String[] line = skill.split("");
        int index = 0;
        for (int i = 0; i < skill_trees.length; i++) {
            String[] target = skill_trees[i].split("");
            boolean isOK = true;
            index = 0;
            for (int j = 0; j < target.length; j++) {
                if (skill.contains(target[j])) {
                    if (line[index].equals(target[j])) {
                        if (index >= line.length) break;
                        index++;
                    } else {
                        isOK = false;
                        break;
                    }
                }
            }
            if (isOK) answer++;
        }
        return answer;
    }
}
