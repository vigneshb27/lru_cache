const express = require('express');
const app = express();
const redditData = require('./data.json');
var fs = require('fs');
const { cache } = require('ejs');

app.use(express.static('public'))

app.set('view engine', 'ejs');
var cache_arr = [];
app.get('/', (req, res) => {
    
    res.render("home.ejs");
})

app.get('/abc', (req, res) => {
    res.render("abc.ejs");
})

app.get('/:subreddit', (req, res) => {
    var readMe = fs.readFileSync('readMeNow.txt','utf8');
    readMe = readMe.toString();
    cache_arr = readMe.split('');
    console.log(cache_arr);

    const {subreddit} = req.params;
    console.log(subreddit);
    const data = redditData[subreddit];
    if(cache_arr.includes(subreddit) && data){
        res.render("subreddit.ejs", {...data});
    }else{
        res.render('404')
    }
})

app.use(function(req,res){
    res.status(404).render('404');
});


app.listen(3000, () => {
    console.log("LISTENING ON PORT 3000");
})