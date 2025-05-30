package Service;

import Entity.TrieNodeEntity;
import Repository.TrieRepository;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

@Service
public class TrieService {

    @Autowired
    private TrieRepository repository;

    public void insert(String word) {
        TrieNodeEntity current = repository.getRoot();
        for (char c : word.toCharArray()) {
            int index = c - 'a';
            if (current.getChildren()[index] == null) {
                current.getChildren()[index] = new TrieNodeEntity();
            }
            current = current.getChildren()[index];
        }
        current.setLast(true);
    }

    public boolean search(String word) {
        TrieNodeEntity current = repository.getRoot();
        for (char c : word.toCharArray()) {
            int index = c - 'a';
            if (current.getChildren()[index] == null) {
                return false;
            }
            current = current.getChildren()[index];
        }
        return current.isLast();
    }

    public boolean startsWith(String prefix) {
        TrieNodeEntity current = repository.getRoot();
        for (char c : prefix.toCharArray()) {
            int index = c - 'a';
            if (current.getChildren()[index] == null) {
                return false;
            }
            current = current.getChildren()[index];
        }
        return true;
    }
}
