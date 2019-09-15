var polish_translation = function()
{
	this.translations = [];
	this.add = function(translation)
	{
		this.translations.push(translation);
	}
}

var word = function()
{
	this.en = "";
	this.pl = new polish_translation;
	this.fill = function(in_english, polish_translations)
	{
		this.en = in_english;
		this.pl = polish_translations;
	}
}

function btn_nullfunc()
{
}

function update_content(in_lang_out_lang, id)
{
	if(window.correct + window.incorrect < window.words.length)
	{
		document.getElementById(id).innerHTML = "<font color=green>" + window.correct + "</font><font color=white> poprawnych, </font><font color=red>" + window.incorrect + "</font><font color=white> niepoprawnych na " + window.words.length + " możliwych.<br><font size=5 color=white face=\"Cantarell\">" + window.words[window.order[window.correct + window.incorrect]].en + "</font><br><input type=\"text\" name=\"answer\" id=\"answer\" placeholder=\"Po polsku...\">\n<button type=\"button\" onclick=\"checkword(\'" + in_lang_out_lang + "\', \'" + id + "\', \'answer\')\">Sprawdź</button><br>";
		console.log("number: " + window.order[window.correct + window.incorrect]);
	}
	else
	{
		document.getElementById(id).innerHTML = "<font color=white face=\"Cantarell\" size=7>Twój wynik</font><br><font color=green size=5>" + window.correct + "</font><font color=white size=5> poprawnych, </font><font color=red size=5>" + window.incorrect + "</font><font color=white size=5> niepoprawnych na " + window.words.length + " możliwych (" + (window.correct / window.words.length * 100) + " %).<br>";
	}
}

function checkword(in_lang_out_lang, id, fieldname)
{
	//document.getElementById(id).innerHTML = "<font color=white>Wpisałeś \"" + document.getElementById(fieldname).value + "\"";
	/* Check match in available translations */
	var tmp = window.words[window.correct + window.incorrect];
	console.log("Got answer: |" + document.getElementById(fieldname).value + "|\n");
	var str = "Possible answers: ";
	console.log("tmp.pl.translations.length: " + window.words[window.correct + window.incorrect].pl.translations.length);
	console.log("tmp.pl.translations.length - 1: " + window.words[window.correct + window.incorrect].pl.translations[window.words[window.correct + window.incorrect].pl.translations.length - 1]);
	for(var i = 0; i < window.words[window.correct + window.incorrect].pl.translations.length; i++)
	{
		str += '|' + window.words[window.correct + window.incorrect].pl.translations[i] + "|, ";
		if(document.getElementById(fieldname).value == window.words[window.correct + window.incorrect].pl.translations[i])
		{
			console.log("Correct answer \"" + document.getElementById(fieldname).value + "\"");
			window.correct++;
			return;
		}
	}
	console.log(str);
	window.incorrect++;
	console.log("Incorrect answer \"" + document.getElementById(fieldname).value + "\"");
	update_content(in_lang_out_lang, id);
}

function randomize(start, stop)
{
	var count = stop - start + 1;
	return (Math.floor((Math.random() * count)) + start);
}

function find_in_array(arr, what)
{
	for(var i = 0; i < arr.length; i++)
	{
		if(arr[i] == what)
		{
			return true;
		}
	}
	return false;
}



function appmain(in_lang_out_lang, id)
{
	document.getElementById(id).innerHTML = "<font face=\"Cantarell\" size=3 color=white>Wczytywanie...</font>";
	document.getElementById(id).innerHTML = "<font face=\"Cantarell\" size=3 color=white>Losowe układanie wyrazów...</font>";
	window.correct = 0; /* Number of correct answers */
	window.incorrect = 0; /* Number of incorrect answers */
	var maxlength = 0;
	if(in_lang_out_lang == "en-pl")
	{
		/* Get maximum input field length */
		for(var i = 0; i < window.words.length; i++)
		{
			var tmp = words[i];
			for(var j = 0; j < tmp.pl.translations.length; j++)
			{
				if(tmp.pl.translations[j].length > maxlength)
				{
					maxlength = tmp.pl.translations[j].length;
				}
			}
		}
		/* Generate random indices */
		window.order = [];
		while(window.order.length < words.length)
		{
			var num = randomize(0, words.length - 1);
			if(!find_in_array(window.order, num))
			{
				window.order.push(num);
			}
		}
		update_content(in_lang_out_lang, id);
	}
}

