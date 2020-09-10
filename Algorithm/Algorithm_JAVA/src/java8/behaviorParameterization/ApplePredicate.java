package java8.behaviorParameterization;
/* 전략 디자인 패턴(strategy design pattern)
*  각 알고리즘(전략)을 캡슐화하는 알고리즘 패밀리를 정의해둔 다음, 런타임에 알고리즘을 선택하는 기법
*  ApplePredicate : 알고리즘 패밀리
*  AppleHeavyWeightPredicate, AppleGreenColorPredicate : 전략
* */
public interface ApplePredicate {
    boolean test(Apple apple);
}
