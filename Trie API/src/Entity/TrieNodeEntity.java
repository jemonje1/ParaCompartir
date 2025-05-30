package Entity;

public class TrieNodeEntity {
    private TrieNodeEntity[] children;
    private boolean isLast;

    public TrieNodeEntity() {
        children = new TrieNodeEntity[26];
        isLast = false;
    }

    public TrieNodeEntity[] getChildren() {
        return children;
    }

    public void setChildren(TrieNodeEntity[] children) {
        this.children = children;
    }

    public boolean isLast() {
        return isLast;
    }

    public void setLast(boolean last) {
        isLast = last;
    }
}
