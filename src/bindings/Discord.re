module Collection = {
    type t('a) = {
        size: int
    };

    [@bs.send] external first : t('a) => 'a;
}

module Embed = {
    type image = {
        url: string
    }
    type footer = {
        text: string
    }
    type t= {
        title: option(string),
        description: option(string),
        image: option(image),
        footer: option(footer)
    }
    let title = (title,embed) => {...embed, title: Some(title)}
    let description = (description, embed) => {...embed, description: Some(description)}
    let image = (image, embed) => {...embed, image: Some(image)}
    let footer = (footer, embed) => {...embed, footer: Some(footer)}

    let create = () => {
        title: None,
        description: None,
        image: None,
        footer: None,
    }
}

type messageEmbed = {
    embed: Embed.t
}

type replyType =
  | Embed(messageEmbed)
  | Str(string)


let toStr = (str) => Str(str)
let toEmbed = (embed: Embed.t) => Embed({embed: embed})

module Ws = {
    type t = {
        ping: int
    }
}



module User = {
    type t = {
        tag: string
    };
    [@bs.send] external avatarURL : (t) => string;
}

module Guild = {
    type t = {
        name: string,
        id: string
    };
    [@bs.send] external iconURL : (t) => string;

}

module Message = {
    type mentions =  {
        users: Collection.t(User.t)
    }
    type t = {
        content: string,
        author: User.t,
        mentions: mentions,
        guild: Guild.t
    };
    [@bs.send] external replyString : (t, string) => t = "reply";
    [@bs.send] external replyEmbed : (t, messageEmbed) => t = "reply";
    let reply = (message, content) => {
        let _ = switch(content){
                 | Embed(content) => replyEmbed(message,content)
                 | Str(content) => replyString(message,content)
                };
        ()
    }
}


module Client = {
    type t = {
        user: User.t,
        ws: Ws.t
    };
    [@bs.module "discord.js"] [@bs.new] external create : unit => t = "Client";
    [@bs.send] external onMessage : (t, [@bs.as "message"] _ , (Message.t => unit)) => unit = "on";
    [@bs.send] external onReady : (t, [@bs.as "ready"] _, unit => unit) => unit = "on";
    [@bs.send] external login : (t, string) => unit;

}