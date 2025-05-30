package Repository;

import Entity.TrieNodeEntity;
import org.springframework.stereotype.Repository;

@Repository
public class TrieRepository {
    private final TrieNodeEntity root = new TrieNodeEntity();

    public TrieNodeEntity getRoot() {
        return root;
    }
}
