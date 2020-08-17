# Review_Mastering the game of Go with deep neural networks and tree search

## Introduction
Alphago는 그동안 불가능의 영역이라 여겨졌던 바둑을 정복하면서 대중에게는 인공지능, 특히 기계학습을 인지시켰고, 연구자들에게는 기계학습 활용의 방벌론을 제시했다. 
인공지능을 실현함에 있어 인류는 다양한 방법을 시도했다. 하지만 재정상의 이유 또는 만족할만한 정확성이나 정밀성을 보장하지 않는다는 이유로 인해 기계학습만이 인공지능의 구현 방법으로써 살아남았고, 현재는 거의 인공지능 = 기계학습이라고 봐도 무방하다.

Alphago는 바둑이라는 제한된 환경 하에 있는 인공지능이다. 인공지능을 구현함에 있어 환경은 매우 중요하다. 환경은 학습을 시킬 변수를 결정짓고, 학습의 방향도 제시한다. 그렇기에 loss function의 구현이 가능하고, 학습이 가능한 것이다.
그렇게 3^361이상의 무지막지한 경우의 수를 포함한 환경에서 Alphago는 suboptimal solution을 학습을 통해 도출해냈고, 판 후이 2단과의 대국을 전승으로 이끌어나가면서 인간을 뛰어넘었음을 입증했다.

나는 Alphago에게 주어진 환경과, 그 환경을 어떻게 활용했는지에 대해 고찰했다.

## Conclusion
Alphago에 주어진 환경은 361칸의 바둑판이다. Extended data table 2를 보면, Neural networks에 input으로 들어가는 변수들을 볼 수 있다. 이를 요약하면 다음과 같다.
###
    1. 착수 정보(흰색 or 검은색 or 빈 칸)
    2. 턴 수
    3. Liberty(인접한 빈 칸)의 수, 그 수의 변화
    4. 따낸 돌 수, 따인 돌 수

해당 input을 보고, 가장 먼저 유추할 수 있는 부분은 Alphago의 학습환경이 이산적으로 표현이 가능하다는 것이다. 따라서 Alphago는 특정 timestep과, field 정보를 하나의 state로 규정하는 것이 가능했다. 각각의 state는 전후관계가 있었고, 이를 timestep = depth인 tree형태로 나타낼 수 있었다. 즉, solution의 탐색을 tree search와 동치였으며, Alphago는 Monte-Carlo tree search, MCTS를 통해 탐색이 가능한 것이다.

또한, 바둑은 각 플레이어에게 모든 정보를 제공하고, 결정론적인(deterministic) 환경이다. 즉, 경우의 수를 고려함에 있어 확률을 배제할 수 있는 특징으로 인해, Alphago의 state tree는 확률요소를 포함하지 않았고, 비교적 단순한 state value search만으로 인공지능을 구현할 수 있었다.

위에 주어진 input중에서 Liberty의 수가 들어간다는 점이 재미있는 부분인데, 이는 바둑의 집 계산 방식을 고려한 input이라고 생각된다. 바둑의 집 계산은 한 색의 바둑돌로 둘러싸인 부분 내부의 점 수를 세는 방식으로 이뤄진다.(공배, 옥집 등의 경우는 집으로 세지 않는다.) 즉, '둘러싸인'이라는 키워드가 집을 세는 핵심이라고 볼 수 있다. 그런데, Liberty의 개수 정보만으로는 같은 색의 바둑돌의 연결을 알 수는 없다. 그럼에도 Alphago가 잘 동작했다는 것은 이 정도의 정보만으로도 충분했다는 것이다. 즉, 환경에 대한 올바른 이해는 변수의 압축을 가능하게하고, input image 크기를 줄여 학습속도를 향상을 꾀할 수 있다.

Alphago의 사례를 보고, 환경의 이해 및 활용은 인공지능의 정확성, 효율성을 증가시킴을 알 수 있었다. 어떻게 보면 환경에 대한 고려는 너무나도 당연한 것이지만, 그 당연한 것을 해내는 방법을 생각하는 것은 많은 고민이 필요할 것이다. 그런 점에서 Alphago의 사례는 기계학습 분야에 있어 이정표로서 활용할 수 있는 모범적인 사례라고 생각한다.

## 참고문헌
- David Silver, Aja Huang, Chris J. Maddison, Arthur Guez, Laurent Sifre, George Van Den Driessche, . . . Demis Hassabis. (2016). Mastering the game of Go with deep neural networks and tree search. Nature, 529(7587), 484-489.
