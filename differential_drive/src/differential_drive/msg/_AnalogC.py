"""autogenerated by genpy from differential_drive/AnalogC.msg. Do not edit."""
import sys
python3 = True if sys.hexversion > 0x03000000 else False
import genpy
import struct


class AnalogC(genpy.Message):
  _md5sum = "2e0957cb939ed78036365a4d8012012f"
  _type = "differential_drive/AnalogC"
  _has_header = False #flag to mark the presence of a Header object
  _full_text = """# 8 * uint16 for IR sensors
uint16 ch1
uint16 ch2
uint16 ch3
uint16 ch4
uint16 ch5
uint16 ch6
uint16 ch7
uint16 ch8

# Say if battery is in use, of if a wall adaptator is present
# value : 1 if on battery, 0 if adaptator present
uint8 on_batt

# cell voltage
float32 cell1
float32 cell2
float32 cell3




"""
  __slots__ = ['ch1','ch2','ch3','ch4','ch5','ch6','ch7','ch8','on_batt','cell1','cell2','cell3']
  _slot_types = ['uint16','uint16','uint16','uint16','uint16','uint16','uint16','uint16','uint8','float32','float32','float32']

  def __init__(self, *args, **kwds):
    """
    Constructor. Any message fields that are implicitly/explicitly
    set to None will be assigned a default value. The recommend
    use is keyword arguments as this is more robust to future message
    changes.  You cannot mix in-order arguments and keyword arguments.

    The available fields are:
       ch1,ch2,ch3,ch4,ch5,ch6,ch7,ch8,on_batt,cell1,cell2,cell3

    :param args: complete set of field values, in .msg order
    :param kwds: use keyword arguments corresponding to message field names
    to set specific fields.
    """
    if args or kwds:
      super(AnalogC, self).__init__(*args, **kwds)
      #message fields cannot be None, assign default values for those that are
      if self.ch1 is None:
        self.ch1 = 0
      if self.ch2 is None:
        self.ch2 = 0
      if self.ch3 is None:
        self.ch3 = 0
      if self.ch4 is None:
        self.ch4 = 0
      if self.ch5 is None:
        self.ch5 = 0
      if self.ch6 is None:
        self.ch6 = 0
      if self.ch7 is None:
        self.ch7 = 0
      if self.ch8 is None:
        self.ch8 = 0
      if self.on_batt is None:
        self.on_batt = 0
      if self.cell1 is None:
        self.cell1 = 0.
      if self.cell2 is None:
        self.cell2 = 0.
      if self.cell3 is None:
        self.cell3 = 0.
    else:
      self.ch1 = 0
      self.ch2 = 0
      self.ch3 = 0
      self.ch4 = 0
      self.ch5 = 0
      self.ch6 = 0
      self.ch7 = 0
      self.ch8 = 0
      self.on_batt = 0
      self.cell1 = 0.
      self.cell2 = 0.
      self.cell3 = 0.

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
      _x = self
      buff.write(_struct_8HB3f.pack(_x.ch1, _x.ch2, _x.ch3, _x.ch4, _x.ch5, _x.ch6, _x.ch7, _x.ch8, _x.on_batt, _x.cell1, _x.cell2, _x.cell3))
    except struct.error as se: self._check_types(se)
    except TypeError as te: self._check_types(te)

  def deserialize(self, str):
    """
    unpack serialized message in str into this message instance
    :param str: byte array of serialized message, ``str``
    """
    try:
      end = 0
      _x = self
      start = end
      end += 29
      (_x.ch1, _x.ch2, _x.ch3, _x.ch4, _x.ch5, _x.ch6, _x.ch7, _x.ch8, _x.on_batt, _x.cell1, _x.cell2, _x.cell3,) = _struct_8HB3f.unpack(str[start:end])
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
      _x = self
      buff.write(_struct_8HB3f.pack(_x.ch1, _x.ch2, _x.ch3, _x.ch4, _x.ch5, _x.ch6, _x.ch7, _x.ch8, _x.on_batt, _x.cell1, _x.cell2, _x.cell3))
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
      _x = self
      start = end
      end += 29
      (_x.ch1, _x.ch2, _x.ch3, _x.ch4, _x.ch5, _x.ch6, _x.ch7, _x.ch8, _x.on_batt, _x.cell1, _x.cell2, _x.cell3,) = _struct_8HB3f.unpack(str[start:end])
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e) #most likely buffer underfill

_struct_I = genpy.struct_I
_struct_8HB3f = struct.Struct("<8HB3f")
