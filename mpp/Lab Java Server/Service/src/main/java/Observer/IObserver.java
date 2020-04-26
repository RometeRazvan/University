package Observer;

import Models.Caritate;
import Models.Donatie;

import java.io.Serializable;
import java.util.List;

public interface IObserver {
    void reloadList(List<Caritate> list);
}
