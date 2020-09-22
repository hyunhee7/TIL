package java8.stream;

import javax.swing.*;
import java.util.List;
import java.util.Map;
import java.util.TreeSet;
import java.util.stream.Stream;

import static java.util.stream.Collectors.counting;
import static java.util.stream.Collectors.groupingBy;

class gStudent{
    String name;
    boolean isMale;
    int grade;
    int ban;
    int score;

    public gStudent(String name, boolean isMale, int grade, int ban, int score) {
        this.name = name;
        this.isMale = isMale;
        this.grade = grade;
        this.ban = ban;
        this.score = score;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public boolean isMale() {
        return isMale;
    }

    public void setMale(boolean male) {
        isMale = male;
    }

    public int getGrade() {
        return grade;
    }

    public void setGrade(int grade) {
        this.grade = grade;
    }

    public int getBan() {
        return ban;
    }

    public void setBan(int ban) {
        this.ban = ban;
    }

    public int getScore() {
        return score;
    }

    public void setScore(int score) {
        this.score = score;
    }

    public String toString(){
        return String.format("[%s, %s, %d학년, %d반, %3d점]",name,isMale?"남":"여",grade,ban,score);
    }
    enum Level{
        HIGH, MID, LOW
    }
}
public class StreamGrouppingBy {
    public static void main(String[] args) {
        gStudent[] stuArr = {
                new gStudent("kim",false,1,1,300),
                new gStudent("lee",true,1,1,250),
                new gStudent("han",false,2,1,100),
                new gStudent("choi",true,1,2,200),
                new gStudent("lau",true,2,2,400),
                new gStudent("big",false,3,1,340),
                new gStudent("hal",false,3,2,220),
                new gStudent("can",true,1,2,110),
                new gStudent("doe",true,1,2,100),
                new gStudent("its",false,3,1,300),
                new gStudent("bang",false,2,2,500),
                new gStudent("tae",true,1,1,300)
        };
        //1. 반별 그룹화
        Map<Integer, List<gStudent>> stuByBan = Stream.of(stuArr).collect(groupingBy(gStudent::getBan));
        for(List<gStudent> ban:stuByBan.values()){
            for(gStudent s: ban) {
                System.out.println(s);
            }
        }
        //2. 성적별로 그룹화
        Map<gStudent.Level, List<gStudent>> stuByLevel = Stream.of(stuArr).collect(groupingBy(s->{
            if(s.getScore() >= 200) return gStudent.Level.HIGH;
            if(s.getScore() >= 100) return gStudent.Level.MID;
            else return gStudent.Level.LOW;
        }));

        TreeSet<gStudent.Level> keySet = new TreeSet<>(stuByLevel.keySet());

        for(gStudent.Level key : keySet) {
            System.out.println("["+key+"]");
            for(gStudent s:stuByLevel.get(key))
                System.out.println(s);
            System.out.println();
        }

        //3. 그룹화 + 통계
        Map<gStudent.Level, Long> stuCntByLevel = Stream.of(stuArr).collect(groupingBy(
                s->{
                    if(s.getScore()>= 200) return gStudent.Level.HIGH;
                    else if(s.getScore() >=100) return gStudent.Level.MID;
                    else return gStudent.Level.LOW;
                }, counting()
        ));

        for(gStudent.Level key : stuCntByLevel.keySet())
            System.out.printf("[%s] - %d명", key, stuCntByLevel.get(key));
        System.out.println();
    }
}
