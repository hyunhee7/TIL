package java8.stream;

import java.util.*;
import java.util.stream.*;

import static java.util.stream.Collectors.*;

public class StreamCollect {
    public static void main(String[] args) {
        Student[] stuArr = {
                new Student("이", 3, 300),
                new Student("김", 1, 200),
                new Student("박", 2, 100),
                new Student("장", 3, 150),
                new Student("최", 2, 290),
                new Student("나", 3, 180)
        };
        //학생이름만 뽑아 List에 저장
        List<String> names = Stream.of(stuArr).map(Student::getName).collect(Collectors.toList());
        System.out.println(names);
        //스트림을 배열로 변환
        Student[] stuArr2 = Stream.of(stuArr).toArray(Student[]::new);
        for (Student s : stuArr2)
            System.out.println(s);
        //스트림을 Map<String, Student>로 변환. 학생 이름이 key
        Map<String, Student> stuMap = Stream.of(stuArr).collect(Collectors.toMap(s->s.getName(),p->p));
        for (String name : stuMap.keySet()) System.out.println(name+"-"+stuMap.get(name));

        long count = Stream.of(stuArr).collect(counting());
        long totalScore = Stream.of(stuArr).collect(summingInt(Student::getTotalScore));
        System.out.println("count="+count);
        System.out.println("totalScore="+totalScore);

        totalScore = Stream.of(stuArr).collect(reducing(0,Student::getTotalScore,Integer::sum));
        System.out.println("totalScore="+totalScore);

        Optional<Student> topStudent = Stream.of(stuArr).collect(maxBy(Comparator.comparingInt(Student::getTotalScore)));
        System.out.println("topStudent"+topStudent.get());
        IntSummaryStatistics stat = Stream.of(stuArr).collect(summarizingInt(Student::getTotalScore));
        System.out.println(stat);

        String stuNames = Stream.of(stuArr).map(Student::getName).collect(joining(",","{","}"));
        System.out.println(stuNames);
    }
}
