package java8.behaviorParameterization;

import java.util.ArrayList;
import java.util.List;

public class behaviorParameterization {
    /*
        사과의 어떤 속성에 기초해서  boolean값을 반환
     */
    public static List<Apple> filterApples1(List<Apple> inventory, String color) {
        List<Apple> result = new ArrayList<>();
        for (Apple apple : inventory){
            if(apple.getColor().equals(color)){
                result.add(apple);
            }
        }
        return result;
    }

    public static List<Apple> filterApples2(List<Apple> inventory, ApplePredicate p){
        List<Apple> result = new ArrayList<>();
        for(Apple apple: inventory){
            if(p.test(apple)){
                result.add(apple);
            }
        }
        return result;
    }
    public static void prettyPrintApple(List<Apple> inventory, AppleFormatter formatter){
        for(Apple apple: inventory){
            String output = formatter.accept(apple);
            System.out.println(output);
        }
    }
    public static void main(String[] args) {
        List<Apple> inventory = new ArrayList<>();
        List<Apple> greenApples = filterApples1(inventory, "green");
        List<Apple> redApples = filterApples1(inventory, "red");

        //AppleRedAndHeavyPredicat 객체 전달 ==> filterApples 메서드 동작이 결정된다.
       List<Apple> redAndHeavyApples = filterApples2(inventory, new AppleRedAndHeavyPredicate());

       //[퀴즈2-1] 유연한 API를 위한 동작 파라미터화
       prettyPrintApple(inventory, new AppleFancyFormatter());
       prettyPrintApple(inventory, new AppleSimpleFormatter());
    }
}


