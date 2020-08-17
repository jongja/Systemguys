# Review_Mastering the game of Go with deep neural networks and tree search

## Introduction
Deep mind에서는 바둑(Game of Go)을 대상으로한 인공지는 프로그램 "AlphaGO"의 개발을 진행했다. 
AlphaGO는 deep neural network와 MCTS(Monte-Carlo Tree Search)를 결합하여 여러 바둑 프로그램들을 대상으로 높은 승률을 보여주었다.
이 AlphaGO는 3단계의 training pipeline을 거쳐 metadata를 이룬다.
1단계는 supervised learning(SL)을 진행한다. 이 논문에서는 13개의 layer를 사용하여 network를 구성하였다. 이 1단계를 통해 classification을 진행하게 한다.
2단계는 policy에 대한 reinforcement learning(RL)을 진행한다. 이 부분에서는 이전의 결과를 이용하여 승리를 할 수 있는 방법에 대한 강화를 진행한다.
3단계는 value 에 대한 reinforcement learning을 진행한다.

이렇게 훈련시킨 최종 버전의 AlphaGO는 40개의 searching threads와 48개의 CPU, 8개의 GPU를 사용한다.
Evaluation 결과 AlphaGO는 기존 바둑 프로그램에 대해 엄청나게 높은 승률을 보여주었다.

## Conclusion
이 논문은 2016년에 나온 AlphaGO에 대한 논문이다. 특히 세계적으로는 "이세돌"과의 경기를 통하여 전세계를 충격에 빠뜨렸으며 이 때 "이세돌"의 처음이자 마지막의 승리로 AI와의 바둑경기를 마무리했다.
이 논문과 "이세돌"과의 결전이후로 많은 사람들은 AI에 관심을 가지고 각자 공부하기 시작했고, 'tensorflow'나 'keras'와 같은 딥러닝을 위한 프로그램들이 소개되었다.
나도 딥러닝을 통한 많은 프로젝트를 진행해 온 경험이 있다. 어떻게 보면 AI는 많은 부분에서 하지 못할 일들이 없을 것 같은 대단한 것 처럼 보인다.
하지만 개인적으로 아직은 AI는 많은 부분에서 개선이 되어야 한다는 점이다. 위의 논문의 요약에서 많은 CPU들과 GPU들을 사용하여 바둑을 이기는 프로그램을 만들었지만 사실 우리가 원하는 인공지능은 보다 더 많은
상황이 고려되어 판단을 해야하므로 AlphaGO가 가지고 있는 성능보다 더 좋은 디바이스들을 이용해야 하지 않을까 싶다. 
또한, "이세돌"이 이길 수 있었던 결정적인 이유는 3단계를 통하여 학습한 AlphaGO가 학습되지 않았던 0.007%의 한수이다. 이론적으로 생각해보면 이게 일어날 수 있는 확률은 '매우 작다' 라고 할 수 있으나
실제 우리가 원하는 AI가 적용이 되기 위해서는 이 '매우 적은' 확률도 할 수 있도록 해야하는 상황이 여러 존재할 수 있다.

2016년 출간되어 많은 사람들에게 놀라움을 보여준 이 논문을 리뷰하며, 2020년 현재 AI는 어디까지 왔는가에 대해 생각해 보았다.
많은 부분에 있어서 성장이 있었지만 인간이 스마트폰을 발명하여 달라진 삶보다는 많이 느껴지지 않는 것 같다.

## 참고문헌
- David Silver, Aja Huang, Chris J. Maddison, Arthur Guez, Laurent Sifre, George Van Den Driessche, . . . Demis Hassabis. (2016). Mastering the game of Go with deep neural networks and tree search. Nature, 529(7587), 484-489.