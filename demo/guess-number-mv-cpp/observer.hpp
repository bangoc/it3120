#ifndef OBSERVER_HPP_
#define OBSERVER_HPP_

class GameModel;

class Observer {
public:
  virtual void Update(GameModel *model) = 0;
  void SetModel(GameModel *m) {
    model = m;
  }
protected:
  GameModel *model;
};

#endif  // OBSERVER_HPP_