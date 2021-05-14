module Collection = {
    type t('a) = {
        size: int
    };

    [@bs.send] external get : (t('a), string) => option('a);
    [@bs.send] external filter : (t('a),'a => bool ) => t('a);
    [@bs.send] external map : (t('a),'a => 'b ) => array('b);
    [@bs.send] external first : t('a) => 'a;
}

module Embed = {
    type image = {
        url: string
    }
    type footer = {
        text: string
    }
    type field = {
        name: string,
        value: string,
        inline: bool
    }
    type t= {
        title: option(string),
        description: option(string),
        image: option(image),
        footer: option(footer),
        fields: array(field),
        thumbnail: option(image),
        color: option(int)
    }
    let title = (title,embed) => {...embed, title: Some(title)}
    let description = (description, embed) => {...embed, description: Some(description)}
    let image = (image, embed) => {...embed, image: Some(image)}
    let footer = (footer, embed) => {...embed, footer: Some(footer)}
    let thumbnail = (thumbnail, embed) => {...embed, thumbnail: Some(thumbnail)}
    let color = (color, embed) => {...embed, color: Some(color)}
    let addField = (field, embed) => {
            ...embed,
            fields: Array.append(embed.fields, [|field|])
        }
    
    let create = () => {
        title: None,
        description: None,
        image: None,
        footer: None,
        fields: [||],
        thumbnail: None,
        color: None
    }
}

type messageBuffer

type messageEmbed = {
    embed: Embed.t
}

type replyType =
  | Embed(messageEmbed)
  | Str(string)
  | Buffer(messageBuffer)


let toStr = (str) => Str(str)
let toEmbed = (embed) => Embed({embed: embed})
let toBuffer = (buffer) => Buffer(buffer)

module Ws = {
    type t = {
        ping: int
    }
}



module User = {
    type t = {
        tag: string,
        id: string,
        createdTimestamp: float
    };
    type imageUrl = {
        format: string,
        size: int
    };
    [@bs.send] external avatarURL : (t) => string;
    [@bs.send] external displayAvatarURL : (t, imageUrl) => string;
}

module Channel = {
    type t = {
        name: string,
        id: string,
    };
   [@bs.get] external getType : t => string = "type"
}
module Role = {
    type t = {
        name: string,
        id: string,
        color: int
    }
}

module Member = {
    type t = {
        user: User.t
    };
}

module Guild = {
    type members = {
        cache: Collection.t(Member.t)
    }
    type roles = {
        cache: Collection.t(Role.t)
    }
    type channels = {
        cache: Collection.t(Channel.t)
    }
    type t = {
        name: string,
        id: string,
        members,
        roles,
        channels,
        owner: Member.t
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
    [@bs.send] external replyBuffer : (t, messageBuffer) => t = "reply";
    [@bs.send] external replyString : (t, string) => t = "reply";
    [@bs.send] external replyEmbed : (t, messageEmbed) => t = "reply";
    let reply = (message, content) => {
        let _ = switch(content){
                 | Embed(content) => replyEmbed(message, content)
                 | Str(content) => replyString(message, content)
                 | Buffer(content) => replyBuffer(message, content)
                };
        ()
    }
}


module Client = {
    type guilds = {
        cache:  Collection.t(Guild.t)
     }
    type t = {
        user: User.t,
        ws: Ws.t,
        guilds: guilds
    };
    [@bs.module "discord.js"] [@bs.new] external create : unit => t = "Client";
    [@bs.send] external onMessage : (t, [@bs.as "message"] _ , (Message.t => unit)) => unit = "on";
    [@bs.send] external onReady : (t, [@bs.as "ready"] _, unit => unit) => unit = "on";
    [@bs.send] external login : (t, string) => unit;

}
[@bs.module "discord.js"] [@bs.new] external messageAttachment: (Js_typed_array.array_buffer, string) => messageBuffer = "MessageAttachment";