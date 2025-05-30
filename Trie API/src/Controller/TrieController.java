package controller;

import Model.WordModel;
import Service.TrieService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;

@RestController
@RequestMapping("/trie")
public class TrieController {

    @Autowired
    private TrieService trieService;

    @PostMapping("/insert")
    public String insert(@RequestBody WordModel wordModel) {
        trieService.insert(wordModel.getWord().toLowerCase());
        return "Word inserted: " + wordModel.getWord();
    }

    @GetMapping("/search")
    public boolean search(@RequestParam String word) {
        return trieService.search(word.toLowerCase());
    }

    @GetMapping("/prefix")
    public boolean prefix(@RequestParam String prefix) {
        return trieService.startsWith(prefix.toLowerCase());
    }
}
