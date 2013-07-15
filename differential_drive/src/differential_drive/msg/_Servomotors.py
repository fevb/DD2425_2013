"""autogenerated by genpy from differential_drive/Servomotors.msg. Do not edit."""
import sys
python3 = True if sys.hexversion > 0x03000000 else False
import genpy
import struct


class Servomotors(genpy.Message):
  _md5sum = "f51d948c20e299a516b60c1bba9b447f"
  _type = "differential_drive/Servomotors"
  _has_header = False #flag to mark the presence of a Header object
  _full_text = """# desired angular position
# range 0-180 degrees

uint8 servo1
uint8[8] servoangle

"""
  __slots__ = ['servo1','servoangle']
  _slot_types = ['uint8','uint8[8]']

  def __init__(self, *args, **kwds):
    """
    Constructor. Any message fields that are implicitly/explicitly
    set to None will be assigned a default value. The recommend
    use is keyword arguments as this is more robust to future message
    changes.  You cannot mix in-order arguments and keyword arguments.

    The available fields are:
       servo1,servoangle

    :param args: complete set of field values, in .msg order
    :param kwds: use keyword arguments corresponding to message field names
    to set specific fields.
    """
    if args or kwds:
      super(Servomotors, self).__init__(*args, **kwds)
      #message fields cannot be None, assign default values for those that are
      if self.servo1 is None:
        self.servo1 = 0
      if self.servoangle is None:
        self.servoangle = chr(0)*8
    else:
      self.servo1 = 0
      self.servoangle = chr(0)*8

  def _get_types(self):
    """
    internal API method
    """
    return self._slot_types

  def serialize(self, buff):
    """
    serialize message into buffer
    :param buff: buffer, ``StringIO``
    """
    try:
      buff.write(_struct_B.pack(self.servo1))
      _x = self.servoangle
      # - if encoded as a list instead, serialize as bytes instead of string
      if type(_x) in [list, tuple]:
        buff.write(_struct_8B.pack(*_x))
      else:
        buff.write(_struct_8s.pack(_x))
    except struct.error as se: self._check_types(se)
    except TypeError as te: self._check_types(te)

  def deserialize(self, str):
    """
    unpack serialized message in str into this message instance
    :param str: byte array of serialized message, ``str``
    """
    try:
      end = 0
      start = end
      end += 1
      (self.servo1,) = _struct_B.unpack(str[start:end])
      start = end
      end += 8
      self.servoangle = str[start:end]
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e) #most likely buffer underfill


  def serialize_numpy(self, buff, numpy):
    """
    serialize message with numpy array types into buffer
    :param buff: buffer, ``StringIO``
    :param numpy: numpy python module
    """
    try:
      buff.write(_struct_B.pack(self.servo1))
      _x = self.servoangle
      # - if encoded as a list instead, serialize as bytes instead of string
      if type(_x) in [list, tuple]:
        buff.write(_struct_8B.pack(*_x))
      else:
        buff.write(_struct_8s.pack(_x))
    except struct.error as se: self._check_types(se)
    except TypeError as te: self._check_types(te)

  def deserialize_numpy(self, str, numpy):
    """
    unpack serialized message in str into this message instance using numpy for array types
    :param str: byte array of serialized message, ``str``
    :param numpy: numpy python module
    """
    try:
      end = 0
      start = end
      end += 1
      (self.servo1,) = _struct_B.unpack(str[start:end])
      start = end
      end += 8
      self.servoangle = str[start:end]
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e) #most likely buffer underfill

_struct_I = genpy.struct_I
_struct_8B = struct.Struct("<8B")
_struct_8s = struct.Struct("<8s")
_struct_B = struct.Struct("<B")
