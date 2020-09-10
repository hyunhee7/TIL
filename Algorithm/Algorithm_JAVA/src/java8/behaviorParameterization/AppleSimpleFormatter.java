package java8.behaviorParameterization;

public class AppleSimpleFormatter implements AppleFormatter{
    public String accept(Apple apple){
        return "An apple of "+apple.getWeight() + "g";
    }
}
