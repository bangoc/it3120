#ifndef OBSERVER_H_
#define OBSERVER_H_

class GameModel;

class Observer {
public:
  virtual void Update(GameModel *model) = 0;
};

#endif  // OBSERVER_H_